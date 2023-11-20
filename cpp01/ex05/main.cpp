/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:29:21 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/20 14:16:30 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void) {
    Harl h;

    h.complain("debug");
    h.complain("debug");
    h.complain("info");
    h.complain("info");
    h.complain("warning");
    h.complain("warning");
    h.complain("error");
    h.complain("error");
    return 0;
}
