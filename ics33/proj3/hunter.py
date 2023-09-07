from prey  import Prey
from pulsator import Pulsator
from mobilesimulton import Mobile_Simulton
from math import atan2
import model
from simulton import Simulton as s1


class Hunter(Pulsator, Mobile_Simulton):  
    
    distance = 200
    
    def __init__(self, x, y):
        Pulsator.__init__(self, x, y)
        self.set_speed(5)
        self.randomize_angle()
        self._color = "Black"
        
    def update(self):
        self.move()
        self.wall_bounce()
        
        super().update()
        
        lst_preys = model.find(lambda x: isinstance(x, Prey))

        if len(lst_preys) != 0:
            min = 201
            
            in_distance = False
            
            for p in lst_preys:
                if s1.distance(self, p.get_location()) <= 200:
                    in_distance = True
            
            if in_distance:
                for p in lst_preys:
                    if s1.distance(self, p.get_location()) <= 200:
                        if s1.distance(self, p.get_location()) < min:
                            min = s1.distance(self, p.get_location())
                            temp = p
                        
         
                x_diff = temp.get_location()[0] - self.get_location()[0] 
                y_diff = temp.get_location()[1] - self.get_location()[1] 
                ang = atan2(y_diff, x_diff)
            
                self.set_angle(ang)
                
            else: 
                pass
                        
        else:
            pass
        
        
        
