/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:42:45 by drestrep          #+#    #+#             */
/*   Updated: 2024/04/18 18:06:10 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEUP = 4,
	ON_MOUSEDOWN = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

# define EMPTY						"Map's empty 😔\n"
# define ERROR_USAGE				"Correct use: ./fdf map_name.fdf\n"
# define WRONGLY_DEFINED_COLOR		"Hexadecimal color not correctly defined\n"
# define WRONGLY_DEFINED_NUMBER		"Number is not correctly defined\n"
# define WRONG_AMOUNT_OF_NUMBERS	"Wrong amount of numbers\n"

# define WIDTH 						1000
# define HEIGHT						1000

# define RED						0xFF0000
# define GREEN						0x00FF00
# define BLUE						0x0000FF
# define BLACK						0x000000
# define WHITE						0xFFFFFF

# define R							15
# define G							5
# define B							11

# define I							34
# define P							35

# define LK							123
# define RK							124
# define DK							125
# define UK							126
# define A							0
# define W							13
# define S							1
# define D							2

# define PLUS						69
# define MINUS 						78

# define CLOSE_WINDOW 				17

# define ESC 						53

#endif