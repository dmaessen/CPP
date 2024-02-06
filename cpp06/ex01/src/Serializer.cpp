/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:36:01 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/29 14:10:52 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
    std::uintptr_t u = reinterpret_cast<std::uintptr_t>(ptr);
    return u;
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data* d = reinterpret_cast<Data*>(raw);
    return d;
}