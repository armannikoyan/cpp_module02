/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:22:52 by anikoyan          #+#    #+#             */
/*   Updated: 2025/04/30 18:35:00 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
  private:
    int fp_value_;
    static const int fp_fraction_;

  public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed&);
    Fixed& operator=(const Fixed&);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};
