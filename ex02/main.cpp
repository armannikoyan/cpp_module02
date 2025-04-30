/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:35:08 by anikoyan          #+#    #+#             */
/*   Updated: 2025/04/30 22:54:41 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
  {
    Fixed a;
    Fixed const b(Fixed( 5.05f ) * Fixed( 2 ));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
  }
  {
    Fixed a;
    Fixed b(10);
    Fixed c(5.75f);
    Fixed d(b);
    Fixed e = c;

    std::cout << "\n--- Initial Values ---\n";
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;

    std::cout << "\n--- Comparison Operators ---\n";
    std::cout << "b > c: " << (b > c) << " (expected 1)\n";
    std::cout << "b < c: " << (b < c) << " (expected 0)\n";
    std::cout << "b >= d: " << (b >= d) << " (expected 1)\n";
    std::cout << "c <= e: " << (c <= e) << " (expected 1)\n";
    std::cout << "b == d: " << (b == d) << " (expected 1)\n";
    std::cout << "a != b: " << (a != b) << " (expected 1)\n";

    std::cout << "\n--- Arithmetic Operators ---\n";
    Fixed sum = b + c;
    Fixed diff = b - c;
    Fixed prod = b * c;
    Fixed quot = b / c;

    std::cout << "b + c: " << sum << " (expected 15.75)\n";
    std::cout << "b - c: " << diff << " (expected 4.25)\n";
    std::cout << "b * c: " << prod << " (expected 57.5)\n";
    std::cout << "b / c: " << quot << " (expected ~1.73913)\n";

    // Test division by zero
    try {
      Fixed zero(0);
      Fixed danger = b / zero;
    } catch (const std::exception& e) {
      std::cout << "Division by zero error: " << e.what();
    }

    std::cout << "\n\n--- Increment/Decrement Operators ---\n";
    std::cout << "Initial a: " << a << std::endl;
    std::cout << "Pre-increment: " << ++a << std::endl;
    std::cout << "Post-increment: " << a++ << std::endl;
    std::cout << "After post-inc: " << a << std::endl;
    std::cout << "Pre-decrement: " << --a << std::endl;
    std::cout << "Post-decrement: " << a-- << std::endl;
    std::cout << "After post-dec: " << a << std::endl;

    std::cout << "\n--- Min/Max Functions ---\n";
    Fixed& min_ref = Fixed::min(b, c);
    Fixed& max_ref = Fixed::max(b, c);
    const Fixed& const_min_ref = Fixed::min(b, c);
    const Fixed& const_max_ref = Fixed::max(b, c);

    std::cout << "min(b, c): " << min_ref << std::endl;
    std::cout << "max(b, c): " << max_ref << std::endl;
    std::cout << "const min(b, c): " << const_min_ref << std::endl;
    std::cout << "const max(b, c): " << const_max_ref << std::endl;

    std::cout << "\n--- Mixed Operations ---\n";
    Fixed result = (++b * c) - (e / Fixed(2.0f));
    std::cout << "(++b * c) - (e / 2.0): " << result << std::endl;

    std::cout << "\n--- Edge Cases ---\n";
    Fixed big(8388607); // Max positive value for 8.24 fixed point
    Fixed small(-8388608); // Min negative value
    std::cout << "Big: " << big << std::endl;
    std::cout << "Small: " << small << std::endl;

    std::cout << "\n--- Copy Assignment ---\n";
    Fixed f;
    f = big;
    std::cout << "f after assignment: " << f << std::endl;
  }
  return 0;
}
