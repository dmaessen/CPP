#include "../include/PmergeMe.hpp"

void PmergeMe::sort(std::vector<unsigned int> &arr)
{
	std::vector<Pair> X;
	std::vector<Pair> pairs;

	for (size_t i = 0; i < arr.size(); i++)
	{
		unsigned int value = arr[i];

		Pair pair = {
			.value = value,
			.index = pairs.size(),
			.smallParentIndex = SIZE_MAX,
			.bigParentIndex = SIZE_MAX,
			.depth = 0,
		};

		X.push_back(pair);
		pairs.push_back(pair);
	}

	std::vector<Pair> S;
	mergeinsertionSort(X, S, pairs, 1);

	for (size_t i = 0; i < S.size(); i++) { // to put them back
		arr[i] = S[i].value;
	}
}

void PmergeMe::mergeinsertionSort(std::vector<Pair> &X, std::vector<Pair> &S, std::vector<Pair> &pairs, size_t depth)
{
	if (X.size() == 1) {
		S.push_back(X[0]);
		return;
	}

	std::vector<Pair> childPairs;
	for (size_t i = 1; i < X.size(); i += 2) {
		Pair *smallParent;
		Pair *bigParent;

		if (X[i - 1].value > X[i].value) {
			smallParent = &X[i];
			bigParent = &X[i - 1];
		}
		else {
			smallParent = &X[i - 1];
			bigParent = &X[i];
		}

		unsigned int value = bigParent->value;

		Pair pair = {
			.value = value,
			.index = pairs.size(),
			.smallParentIndex = smallParent->index,
			.bigParentIndex = bigParent->index,
			.depth = depth,
		};

		childPairs.push_back(pair);
		pairs.push_back(pair);
	}

	mergeinsertionSort(childPairs, S, pairs, depth + 1);
	S.insert(S.begin(), pairs[S[0].smallParentIndex]);

	std::vector<Pair> S_copy(S);

	// Insert S_copy Y values at indices 3 -> 2 -> 5 -> 4 -> 11 -> ...
	size_t prevHighestIndex = 1;
	size_t powerOfTwo = 4;
	while (prevHighestIndex + 1 < S_copy.size())
	{
		size_t wouldBeHighestIndex = powerOfTwo - prevHighestIndex;
		size_t highestIndex = std::min(wouldBeHighestIndex, S_copy.size() - 1);
		size_t index = highestIndex;

		size_t missingElements = wouldBeHighestIndex - highestIndex;
		size_t elementsPlacedAtEnd = 0;

		// Insert S_copy Y values at indices 3 -> 2, or 5 -> 4
		while (index > prevHighestIndex) {
			Pair *big_parent = &S_copy[index];
			while (big_parent->depth > depth) {
				big_parent = &pairs[big_parent->bigParentIndex];
			}

			if (insertionSort(S, powerOfTwo - 1 - missingElements - elementsPlacedAtEnd, pairs[big_parent->smallParentIndex])) {
				elementsPlacedAtEnd++;
			}
			index--;
		}
		powerOfTwo <<= 1;
		prevHighestIndex = highestIndex;
	}

	if (X.size() % 2 == 1)
		insertionSort(S, S.size(), X.back());
}

bool PmergeMe::insertionSort(std::vector<Pair> &S, size_t subsequenceLen, Pair &pair)
{
	unsigned int value = pair.value;
	size_t start = 0;
	size_t end = subsequenceLen;

	while (start < end) {
		size_t halfwayIndex = (start + end) / 2;
		Pair &halfwayPair = S[halfwayIndex];
		unsigned int halfwayValue = halfwayPair.value;

		if (halfwayValue < value) {
			start = halfwayIndex + 1;
		}
		else {
			end = halfwayIndex;
		}
	}

	S.insert(S.begin() + start, pair);

	// Return whether the value was placed at the end, so future subsequence lengths can be shorter
	return start == subsequenceLen;
}

