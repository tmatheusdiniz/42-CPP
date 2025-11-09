/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:25:53 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/25 22:08:52 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void testCase(std::string testName, Point const& a, Point const& b, Point const& c, Point const& point, bool expected)
{
    bool result = bsp(a, b, c, point);
    std::cout << testName << ": ";
    if (result == expected)
        std::cout << "✓ PASS";
    else
        std::cout << "✗ FAIL (expected " << (expected ? "true" : "false") << ", got " << (result ? "true" : "false") << ")";
    std::cout << std::endl;
}

int main(void)
{
    std::cout << "=== BSP Triangle Point Test ===" << std::endl << std::endl;

    // Define a standard triangle
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    std::cout << "Triangle vertices: A(0,0), B(10,0), C(5,10)" << std::endl << std::endl;

    // Test 1: Point clearly inside
    std::cout << "--- Inside Triangle Tests ---" << std::endl;
    testCase("Center point (5, 5)", a, b, c, Point(5.0f, 5.0f), true);
    testCase("Point (5, 3)", a, b, c, Point(5.0f, 3.0f), true);
    testCase("Point (3, 2)", a, b, c, Point(3.0f, 2.0f), true);
    testCase("Point (7, 2)", a, b, c, Point(7.0f, 2.0f), true);

    // Test 2: Points on edges (should return false)
    std::cout << std::endl << "--- On Edge Tests (should be false) ---" << std::endl;
    testCase("Point on AB edge (5, 0)", a, b, c, Point(5.0f, 0.0f), false);
    testCase("Point on AC edge (2.5, 5)", a, b, c, Point(2.5f, 5.0f), false);
    testCase("Point on BC edge (7.5, 5)", a, b, c, Point(7.5f, 5.0f), false);

    // Test 3: Points on vertices (should return false)
    std::cout << std::endl << "--- On Vertex Tests (should be false) ---" << std::endl;
    testCase("Point on vertex A (0, 0)", a, b, c, Point(0.0f, 0.0f), false);
    testCase("Point on vertex B (10, 0)", a, b, c, Point(10.0f, 0.0f), false);
    testCase("Point on vertex C (5, 10)", a, b, c, Point(5.0f, 10.0f), false);

    // Test 4: Points clearly outside
    std::cout << std::endl << "--- Outside Triangle Tests ---" << std::endl;
    testCase("Point below (5, -1)", a, b, c, Point(5.0f, -1.0f), false);
    testCase("Point above (5, 11)", a, b, c, Point(5.0f, 11.0f), false);
    testCase("Point left (-1, 5)", a, b, c, Point(-1.0f, 5.0f), false);
    testCase("Point right (11, 5)", a, b, c, Point(11.0f, 5.0f), false);
    testCase("Point far away (100, 100)", a, b, c, Point(100.0f, 100.0f), false);

    // Test 5: Degenerate triangle (collinear points)
    std::cout << std::endl << "--- Degenerate Triangle Test ---" << std::endl;
    Point d(0.0f, 0.0f);
    Point e(5.0f, 0.0f);
    Point f(10.0f, 0.0f);
    testCase("Collinear triangle", d, e, f, Point(5.0f, 5.0f), false);

    // Test 6: Different triangle shape
    std::cout << std::endl << "--- Different Triangle Shape ---" << std::endl;
    Point g(0.0f, 0.0f);
    Point h(4.0f, 0.0f);
    Point i(0.0f, 3.0f);
    std::cout << "Right triangle: G(0,0), H(4,0), I(0,3)" << std::endl;
    testCase("Inside (1, 1)", g, h, i, Point(1.0f, 1.0f), true);
    testCase("Outside (2, 2)", g, h, i, Point(2.0f, 2.0f), false);
    testCase("On hypotenuse", g, h, i, Point(2.0f, 1.5f), false);

    // Test 7: Negative coordinates
    std::cout << std::endl << "--- Negative Coordinates ---" << std::endl;
    Point j(-5.0f, -5.0f);
    Point k(5.0f, -5.0f);
    Point l(0.0f, 5.0f);
    std::cout << "Triangle: J(-5,-5), K(5,-5), L(0,5)" << std::endl;
    testCase("Inside (0, 0)", j, k, l, Point(0.0f, 0.0f), true);
    testCase("Outside (0, -6)", j, k, l, Point(0.0f, -6.0f), false);

    std::cout << std::endl << "=== Tests Complete ===" << std::endl;

    return 0;
}
