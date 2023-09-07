from prey import Prey
from random import random


class Floater(Prey): 
    
    radius = 5
    
    def __init__(self, x, y):
        Prey.__init__(self, x, y, 10, 10, 0, 5)
        self.randomize_angle()
        self._color = "RED"
        
    def update(self):
        random_num = random()
        random_num =random_num * 100
        
        if random_num < 30:
            temp_change = random() - 0.5
            
            new_temp = self.get_speed() + temp_change
            if new_temp > 7 :
                new_temp = 7
            elif new_temp < 3:
                new_temp = 3
                
            self.set_speed(new_temp)
            
            
            angle_change = random() - 0.5
            new_angle = self.get_angle() + angle_change
            self.set_angle(new_angle)
        
        else:
            pass
        
        
        self.move()
        self.wall_bounce()
    
    def display(self, canvas):
        canvas.create_oval(self._x-Floater.radius, self._y-Floater.radius, self._x+Floater.radius, self._y+Floater.radius, fill=self._color)
