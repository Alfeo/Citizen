/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   citizen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelabre <fdelabre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/25 17:12:51 by fdelabre          #+#    #+#             */
/*   Updated: 2014/07/25 22:24:52 by fdelabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{	
	char	buf[1000];
	int		fd;
	int		map;

	fd = open(argv[1], O_RDONLY);
	map = read(fd, buf, 1000);
	buf[map] = '\0';
	if (argc >= 1)
		ft_citizen(buf);
	return(0);
}

int		ft_citizen(char *buf)
{
	int 	fin;
	int 	lg;
	int		x;
	int 	vie;
	int		exp;
	char	move[5];
	int		pierre;
	int 	bois;
	
	x = 0;
	lg = 0;
	fin = 0;
	exp = 0;
	vie = 100;
	bois = 0;
	pierre = 0;
	while (buf[lg] != '\n')
		lg++;
	while (buf[x] == '|' || buf[x] == '\n')
	{
		x++;
		if (buf[x] == ' ')
		{
			buf[x] = '{';
			printf(buf);
		}
	}
	while (fin == 0)
	{
		scanf("%s", move);
		if (move[0] == 'd')
		{
			buf[x] = ' ';
			x = x + 1;
			if (buf[x] == '|' || buf[x] == 'O' || buf[x] == 'I' || buf[x] == 'M')
				x = x - 1;
			buf[x] = '}';
			system("clear");
			printf(buf);
		}
		else if (move[0] == 'a')
		{
			buf[x] = ' ';
			x = x - 1;
			if (buf[x] == '|' || buf[x] == 'O' || buf[x] == 'I' || buf[x] == 'M')
				x = x + 1;
			buf[x] = '{';
			system("clear");
			printf(buf);
		}
		else if (move[0] == 'w')
		{
			if (buf[x - 1] == ':' || buf[x + 1] == ':')
			{
				buf[x] = ' ';
				x = x - (lg + 1);
				if (buf[x] == '|' || buf[x] == 'O' || buf[x] == 'I' || buf[x] == 'M')
					x = x + (lg + 1);
				buf[x] = '^';
				system("clear");
				printf(buf);	
			}
		}
		else if (move[0] == 's')
		{
			buf[x] = ' ';
			x = x + (lg + 1);
			if (buf[x] == '|' || buf[x] == 'O' || buf[x] == 'I' || buf[x] == 'M')
				x = x - (lg + 1);
			buf[x] = 'v';
			system("clear");
			printf(buf);
		}
		else if (move[0] == 'k')
		{
			if (buf[x + 1] == 'I')
			{
				system("clear");
				printf(buf);
				bois = bois + 5;
				buf[x + 1] = ' ';
				buf[x - (lg - 1)] = ' ';
				buf[x - lg] = ' ';
				buf[x - (lg + 1)] = ' ';
				buf[x - (lg * 2)] = ' ';
				buf[x - ((lg * 2) + 1)] = ' ';
				buf[x - ((lg * 2) + 2)] = ' ';
				buf[x - ((lg * 3) + 2)] = ' ';
				system("clear");
				printf(buf);
			}
			else if (buf[x - 1] == 'I')
			{
				bois = bois + 5;
				buf[x - 1] = ' ';
				buf[x - (lg + 1)] = ' ';
				buf[x - (lg + 2)] = ' ';
				buf[x - (lg + 3)] = ' ';
				buf[x - ((lg * 2) + 2)] = ' ';
				buf[x - ((lg * 2) + 3)] = ' ';
				buf[x - ((lg * 2) + 4)] = ' ';
				buf[x - ((lg * 3) + 4)] = ' ';
				system("clear");
				printf(buf);
			}
			else
			{
				system("clear");
				printf(buf);
				printf("\nIl n'y a rien a couper !\n\n");
			}
		}
		else if (move[0] == 'p')
		{
			if (buf[x + 1] == 'M')
			{
				buf[x + 1] = ' ';
				pierre = pierre + 3;
				system("clear");
				printf(buf);
			}
			else if (buf[x - 1] == 'M')
			{
				buf[x - 1] = ' ';
				pierre = pierre + 3;
				system("clear");
				printf(buf);
			}
			else
			{
				system("clear");
				printf(buf);
				printf("Il n'y a rien a miner !\n\n");
			}
		}
		else
		{
			system("clear");
			printf(buf);
			printf("Cette commande n'existe pas !");
		}
		printf("Commande :\nk = Couper un arbre.                   Bois = %d\np = Miner.                           Pierre = %d\nW A S D = Deplacements.                 Vie = %d\n                                        Exp = %d\n=================================================", bois, pierre, vie, exp); 
	}
	return (0);
}
