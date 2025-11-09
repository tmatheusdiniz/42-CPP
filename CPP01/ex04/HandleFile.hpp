/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandleFile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:12:17 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/25 16:13:06 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLEFILE_HPP
#define HANDLEFILE_HPP

#include <fstream>
#include <string>
#include <iostream>

std::string replaceOccurence(std::string s, std::string s1, std::string s2);
void handleFile(std::string filename, std::string s1, std::string s2);

#endif
