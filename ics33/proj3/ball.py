
from prey import Prey

class Ball(Prey): 
    
    radius = 5
    
    def __init__(self, x, y):
        Prey.__init__(self, x, y, 10, 10, 0, 5)
        self.randomize_angle()
        self._color = "BLUE"
    

    def update(self):
        self.move()
        self.wall_bounce()
    
    def display(self, canvas):
        canvas.create_oval(self._x-Ball.radius, self._y-Ball.radius, self._x+Ball.radius, self._y+Ball.radius, fill=self._color)
    
        
