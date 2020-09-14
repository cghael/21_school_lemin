#!/usr/bin/env python3
import sys
from termcolor import colored, cprint  # цветной cprint https://pypi.org/project/termcolor/
# from collections import deque # двусторонняя очередь
from tkinter import *
import networkx as nx
import matplotlib.pyplot as plt
from sys import argv
import grafix as gx
import support as s


if __name__ == '__main__':
    # init graph
    # G = nx.Graph()
    data = s.ft_init_graph(argv)
    # print_graph(G)
    # G.Graph('Olt2') {color='red'}

    # ############################### GRAFIX ##############################
    gx.ft_init_window(data.graph)

    # ############################### GRAFIX ##############################
    cprint("\nEND\n", 'magenta')


# ############################### TEST ##############################
