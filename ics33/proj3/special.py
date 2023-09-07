import model

from mobilesimulton import Mobile_Simulton
from simulton import Simulton
from floater import Floater
from math import atan2
from hunter import Hunter
import random

class Special(Floater): 
    
    def __init__(self, x, y):
        Floater.__init__(self, x, y)
        self._color = "Yellow"
    
    def update(self):
        
        super().update
        
        lst_hunters = model.find(lambda x: isinstance(x, Hunter))
        
        if len(lst_hunters) != 0:
            
            min = 121
            
            in_distance = False
            
            for p in lst_hunters:
                if Simulton.distance(self, p.get_location()) <= 120:
                    in_distance = True
            
            if in_distance:
                for p in lst_hunters:
                    if Simulton.distance(self, p.get_location()) <= 121:
                        if Simulton.distance(self, p.get_location()) < min:
                            min = Simulton.distance(self, p.get_location())
                            temp = p
                        
         
                x_diff = self.get_location()[0] - temp.get_location()[0] 
                y_diff = self.get_location()[1] - temp.get_location()[1]  
                ang = atan2(y_diff, x_diff)
            
                rand = random.random() - 0.5
                rand_angle = ang + rand
                
            
                self.set_angle(rand_angle)
                
            else: 
                pass
                        
        else:
            pass
        
        
        self.move()
        self.wall_bounce()
    