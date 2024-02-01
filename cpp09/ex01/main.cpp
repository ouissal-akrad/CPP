/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:45:16 by ouakrad           #+#    #+#             */
/*   Updated: 2024/02/01 15:48:47 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    int i = 1;
    std::string str;
    int num;
    std::stack<int> s;

    if (ac == 2)
    {
            str = av[i];
            std::string::size_type j = 0;
            while (j < str.length())
            {
                if (isDigit(str[j]))
                {
                    num = 0;
                    while (j < str.length() && isDigit(str[j]))
                    {
                        num = num * 10 + (str[j] - '0');
                        j++;
                    }
                    if (num > 9)
                    {
                        std::cout << "Error: Number greater than 9 encountered" << std::endl;
                        return 1;
                    }
                    s.push(num);
                }
                else if (isOperator(str[j]))
                {
                    if (s.size() < 2)
                    {
                        std::cout << "Error: Invalid numbers" << std::endl;
                        return 1;
                    }
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    if (str[j] == '+')
                        s.push(b + a);
                    else if (str[j] == '-')
                        s.push(b - a);
                    else if (str[j] == '*')
                        s.push(b * a);
                    else if (str[j] == '/')
                        s.push(b / a);
                    else if (str[j] == '%')
                        s.push(b % a);
                }
                else if (str[j] != ' ')
                {
                    std::cout << "Error: Invalid input" << std::endl;
                    return 1;
                }
                j++;
            }
            i++;
        std::cout << s.top() << std::endl;
    }
    else
        std::cout << "Invalid args" << std::endl;
    return 0;
}