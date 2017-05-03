#! /usr/bin/env python
# -*- coding: utf-8 -*-

# flag 1=if_Food_Ahead 2=Prog2 3=Prog3 4=RIGHT 5=LEFT 6=MOVE
# vec  0=up 1=right 2=down 3=left
class Node:
    def __init__(self):
        self.x = None
        self.y = None
        self.z = None
        self.flag = 0

ant = []

class Tree:
    def __init__(self):
        self.antx = 0
        self.anty = 0
        self.Energy = 400
        self.food = 0
        self.vec = 1
    
    def if_Food_Ahead(self, node):
        nx = self.antx
        ny = self.anty
        if self.vec == 0:
            ny = ny - 1
        elif self.vec == 1:
            nx = nx + 1
        elif self.vec == 2:
            ny = ny + 1
        else:
            nx = nx - 1
            
        if nx < 0 or nx >= 32 or ny < 0 or ny >= 32:
            run(node.y)
            return

        if ant[nx][ny] == 1:
            run(node.x)
        else:
            run(node.y)

    def Prog2(self, node):
        run(node.x)
        run(node.y)

    def Prog3(self, node):
        run(node.x)
        run(node.y)
        run(node.z)
        
    def move(self):
        self.Energy = self.Energy - 1
        nx = self.antx
        ny = self.anty
        if self.vec == 0:
            ny = ny - 1
        elif self.vec == 1:
            nx = nx + 1
        elif self.vec == 2:
            ny = ny + 1
        else:
            nx = nx - 1

        if nx > 0 or nx >= 32 or ny > 0 or ny >= 32:
            return
        if ant[nx][ny] == 1:
            ant[nx][ny] = 0
            self.food = self.food + 1
            
    def run(self, node):
        if node.flag == 1:
            if_Food_Ahead(node)
        elif node.flag == 2:
            Prog2(node)
        elif node.flag == 3:
            Prog3(node)
        elif node.flag == 4:
            vec = (vec + 1) % 4
        elif node.flag == 5:
            vec = (vec + 3) % 4
        elif node.flag == 6:
            move()

if __name__ == '__main__':
    tree = Tree()
    print "ok"
