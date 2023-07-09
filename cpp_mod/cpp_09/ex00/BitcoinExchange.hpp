/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:21:15 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/07/07 18:22:03 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_hpp
#define BitcoinExchange_hpp


#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>
#include <limits>
#include <set>

class BitcoinExchange{

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &);
};


#endif