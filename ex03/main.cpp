/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:35:08 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/01 00:37:52 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>

#include "Fixed.hpp"
#include "Point.hpp"

void print_header(const std::string& title)
{
  std::cout << "\n=== " << title << " ===\n";
}

void test_fixed_operations()
{
  print_header("Testing Fixed Point Operations");

  Fixed a(5.5f);
  Fixed b(2.2f);
  Fixed c(5.5f);
  Fixed d(-3.0f);

  std::cout << "5.5 + 2.2 = " << (a + b) << " (expected ~7.7)\n";
  std::cout << "5.5 - 2.2 = " << (a - b) << " (expected ~3.3)\n";
  std::cout << "5.5 * 2.2 = " << (a * b) << " (expected ~12.1)\n";
  std::cout << "5.5 / 2.2 = " << (a / b) << " (expected ~2.5)\n";

  std::cout << "\nComparisons:\n";
  std::cout << "5.5 < 2.2? " << (a < b) << " (0)\n";
  std::cout << "5.5 > 2.2? " << (a > b) << " (1)\n";
  std::cout << "5.5 == 5.5? " << (a == c) << " (1)\n";
  std::cout << "5.5 != 5.5? " << (a != c) << " (0)\n";
  std::cout << "-3 <= 5.5? " << (d <= a) << " (1)\n";
  std::cout << "5.5 >= -3? " << (a >= d) << " (1)\n";

  std::cout << "\nIncrement/Decrement:\n";
  Fixed i;
  std::cout << "Start: " << i << "\n";
  std::cout << "Pre++: " << ++i << "\n";
  std::cout << "Post++: " << i++ << " (now " << i << ")\n";
  std::cout << "Pre--: " << --i << "\n";
  std::cout << "Post--: " << i-- << " (now " << i << ")\n";

  std::cout << "\nMin/Max:\n";
  std::cout << "min(5.5, 2.2) = " << Fixed::min(a, b) << "\n";
  std::cout << "max(5.5, -3) = " << Fixed::max(a, d) << "\n";
  const Fixed ca(5.5f), cb(2.2f);
  std::cout << "const min(5.5, 2.2) = " << Fixed::min(ca, cb) << "\n";
}

void test_point_class()
{
  print_header("Testing Point Class");

  Point origin;
  Point p1(Fixed(3), Fixed(4));
  Point p2(p1);

  std::cout << "Origin: (" << origin.getX() << ", " << origin.getY() << ")\n";
  std::cout << "Point 1: (" << p1.getX() << ", " << p1.getY() << ")\n";
  std::cout << "Copied Point: (" << p2.getX() << ", " << p2.getY() << ")\n";
}

void test_bsp()
{
  print_header("Testing BSP Algorithm");

  Point a(Fixed(0), Fixed(0));
  Point b(Fixed(10), Fixed(0));
  Point c(Fixed(5), Fixed(8.66f));

  struct TestCase
  {
    Point p;
    const char* name;
  };

  const TestCase cases[] =
  {
    {Point(Fixed(5), Fixed(2.89f)), "Inside"},
    {Point(Fixed(5), Fixed(10.0f)), "Outside"},
    {Point(Fixed(5), Fixed(0)), "Edge"},
    {a, "Vertex"},
    {Point(Fixed(2), Fixed(2)), "Near Center"},
    {Point(Fixed(-1), Fixed(0)), "Left of A"}
  };

  for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); ++i)
  {
    bool result = bsp(a, b, c, cases[i].p);
    std::cout << std::setw(12) << cases[i].name << ": " 
      << (result ? "INSIDE" : "OUTSIDE") 
      << " \t(" << cases[i].p.getX() << ", " 
      << cases[i].p.getY() << ")\n";
  }
}

void test_edge_cases()
{
  print_header("Testing Edge Cases");

  try
  {
    Fixed a(5);
    Fixed zero(0);
    std::cout << "Attempting 5 / 0: ";
    Fixed result = a / zero;
    std::cout << result << "\n";
  }
  catch (const std::exception& e)
  {
    std::cout << "Error: " << e.what();
  }

  Fixed big(8388607);
  Fixed small(-8388608);
  std::cout << "\nBiggest: " << big << "\n";
  std::cout << "Smallest: " << small << "\n";
}

int main()
{
  test_fixed_operations();
  test_point_class();
  test_bsp();
  test_edge_cases();

  return 0;
}
