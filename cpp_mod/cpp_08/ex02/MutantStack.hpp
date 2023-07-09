/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:18:05 by mbel-bas          #+#    #+#             */
/*   Updated: 2023/07/07 13:39:06 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>(){}
	    MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy){}
        ~MutantStack() {}
		MutantStack<T>  &operator=(const MutantStack<T> &stk){
			this->c = stk.c;
			return (*this);
		}

		    typedef typename std::stack<T>::container_type::iterator iterator;
		    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		    iterator    begin(){
                return (this->c.begin());
            }
            iterator    end(){
                return (this->c.end());
            }
            reverse_iterator    rbegin(){
                return (this->c.rbegin());
            }
            reverse_iterator    rend(){
                return (this->c.rend());
            }
};

#endif