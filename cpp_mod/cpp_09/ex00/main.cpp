/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:21:12 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/07/09 14:34:49 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
bool is_valid_date_val(std::string date, float value) {

  for (int i = 0; i < 4; i++) {
    if (!isdigit(date[i])) {
      std::cout << "year not valid\n";
      return false;
    }
  }


  for (int i = 5; i < 7; i++) {
    if (!isdigit(date[i])) {
      std::cout << "month not valid\n";
      return false;
    }
  }

  if (value > 1000){
    std::cout << "Error: too large a number.\n";
      return false;
  }
  
  if (value < 0){
    std::cout << "Error : not a positive number.\n";
    return false;
  }

  int year, month, day;

  if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
    std::cout << "Error: bad input => "<< date << "\n";
    return false;
  }

  if (year < 1000 || year > 9999) {
    std::cout << "year off limit\n";
    return false;
  }

  if (month < 1 || month > 12) {
    std::cout << "month off limit\n";
    return false;
  }

  if (day < 1 || day > 31) {
    std::cout <<"day off limit\n";
    return false;
  }
  
  if (date[4] != '-' || date[7] != '-' || date.length() != 10) {
    std::cout << "invalid format :: accepted format yy-mm-dd\n";
    return false;
  }
  return true;
}

int main(int ac, char **av)
{
    if (ac ==2)
    {
        std::string filename = av[1];
        std::map<std::string, float> data;
        std::ifstream inputfile(filename);
        if (!inputfile){
            std::cout<<"could not open file.\n";
            return(1);
        }

        std::ifstream data_("data.csv");
        if (!data_)
        {
            std::cout << "data corrupted\n";
            return 1;
        }

        std::string data_line;
        char ch;
        while (data_.get(ch) && ch != '\n');
        while(getline(data_,data_line)){
            const char* del = ",";
            char* date_cs = const_cast<char*>(data_line.c_str());
            char* token = std::strtok(date_cs, del);
            std::string date_data = token;
            token = std::strtok(NULL, del);
            float price = std::stof(token);
            data[date_data] = price;
        }

        std::string line;
        float price;
        char c;
        while (inputfile.get(c) && c != '\n');
        while(getline(inputfile,line)){
          if (!line.size()){
            std::cout << "empty line\n";
            continue;
          }
            const char* delim = " | ";
            char* date_cstr = const_cast<char*>(line.c_str());
            char* t = std::strtok(date_cstr, delim);
            std::string d = t;
            t = std::strtok(NULL, delim);
            if (t)
              price = std::stof(t);
            else{
              std::cout <<"Error: bad input => "<< line <<  "\n";
              continue;
            }

            if (!is_valid_date_val(d,price))
                continue;
            else{
                bool is_in_map = data.find(d) != data.end();
                if (is_in_map)
                    std::cout << d<< " => " << t << " = " << price * data[d]<<"\n";
                else{
                  std::map<std::string, float>::iterator it = data.lower_bound(d);
                  if (it != data.end()) {
                      std::cout << d << " => " << t << " = " << --it->second * price << std::endl;
                  }
                  // std::map<int, std::string>::iterator it = data.lower_bound(d);
                  //std::cout << static_cast<std::string>(data.lower_bound(d)) << std::endl;
                }
            }
        }
    return 0;
    }
    else  
        std::cout << "Usage ./btc filename  \n";

  return 0;
}