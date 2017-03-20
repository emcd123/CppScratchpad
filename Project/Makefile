# Makefile for programs from Lab 7 1617-CSS19
# Author: Niall Madden (Niall.Madden@NUIGalway.ie)
# Date: 13/03/2017

all : MakeGraphs Adj2Dot

MakeGraphs : MakeGraphs.cpp Vector09.cpp Vector09.h Matrix09.cpp Matrix09.h
	g++ -Wall MakeGraphs.cpp \
	Vector09.cpp Matrix09.cpp -o MakeGraphs

Adj2Dot : Adj2Dot.cpp
	g++ -Wall Adj2Dot.cpp -o Adj2Dot
