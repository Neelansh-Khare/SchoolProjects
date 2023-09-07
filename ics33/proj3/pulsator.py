import model

from blackhole import Black_Hole


class Pulsator(Black_Hole): 
    
    constant_counter = 30
    
    def __init__(self, x, y):
        Black_Hole.__init__(self, x, y)
        self._color = "Black"
        self.pulsator_counter = 0
        
        
    def update(self):
        
        if self.pulsator_counter == 30:
            self.change_dimension(-1, -1)
            self.pulsator_counter = 0
        
        if self.get_dimension() == (0,0):
            model.remove(self)
        
        eaten = Black_Hole.update(self)
        
        if len(eaten) > 0: 
            for x in eaten:
                self.change_dimension(1, 1)
                self.pulsator_counter = 0
                
        else:
            self.pulsator_counter += 1
        
       
            
                

    
    