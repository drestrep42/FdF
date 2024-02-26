/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:16:29 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/23 17:13:30 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	interpolate(int	start_color, int end_color, int t)
{
	return (start_color + (end_color - start_color) * t);
}

/* typedef struct {
    int hex; // Representación hexadecimal del color
} Color;

// Función para interpolar entre dos colores
Color interpolate(Color start, Color end, float t) {
    Color result;
    result.hex = (int)(start.hex + (end.hex - start.hex) * t);
    return result;
}

// Función principal
int main() {
    Color startColor = {0x0000FF}; // Color azul
    Color endColor = {0xFF0000};   // Color rojo
    
    int numSteps = 10; // Número de pasos entre los dos colores
    float stepSize = 1.0 / numSteps;
    
    printf("Gradiente de color de azul a rojo:\n");
    
    for (int i = 0; i <= numSteps; i++) {
        float t = i * stepSize;
        Color currentColor = interpolate(startColor, endColor, t);
        printf("Paso %d: #%06X\n", i, currentColor.hex);
    }
    
    return 0;
} */