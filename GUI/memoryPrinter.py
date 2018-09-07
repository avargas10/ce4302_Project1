
# Simple enough, just import everything from tkinter.
from tkinter import *


# Here, we are creating our class, Window, and inheriting from the Frame
# class. Frame is a class from the tkinter module. (see Lib/tkinter/__init__)
class MemoryWindow(Frame):
    
    # Define settings upon initialization. Here you can specify
    def __init__(self,num, master=None):
        self.node = num
        self.data=[StringVar() for i in range(16)]

        # parameters that you want to send through the Frame class. 
        Frame.__init__(self, master)   

        #reference to the master widget, which is the tk window                 
        self.master = master
        #with that, we want to then run init_window, which doesn't yet exist
        self.init_window()
    #Creation of init_window
    def init_window(self):

        # changing the title of our master widget      
        self.master.title("Multiprocessor with shared Memory")

        # allowing the widget to take the full space of the root window
        self.pack(fill=BOTH, expand=1)
        self.config(background="grey")

        # creating a menu instance
        menu = Menu(self.master)
        self.master.config(menu=menu)

        # create the file object)py
        file = Menu(menu)
        # adds a command to the menu option, calling it exit, and the
        # command it runs on event is client_exit
        file.add_command(label="Exit", command=self.client_exit)

        #added "file" to our menu
        menu.add_cascade(label="File", menu=file)

        # create the file object)
        edit = Menu(menu)

        # adds a command to the menu option, calling it exit, and the
        # command it runs on event is client_exit
        edit.add_command(label="Undo")

        #added "file" to our menu
        menu.add_cascade(label="Edit", menu=edit)
        #cache1
        self.setImage(1,20,35,"memory.png")
        self.setLabel(1,20,165,"Position")
        self.setLabel(1,140,165,"  Data  ")
        self.createLine(40,188,self.data)
    def client_exit(self):
        exit()

    def setImage(self,num,posX,posY,file):
    	photo = PhotoImage(file="assets/"+file)
    	w = Label(self, image=photo)
    	w.photo = photo
    	w.place(x=posX, y=posY)

    def setLabel(self,num,posX,posY,ptext):
        w = Label(self, text="Rouge", fg="red")
        w = Label(self, text=ptext, font=("Helvetica", 16),background="gray")
        w.place(x=posX, y=posY)


    def createLine(self,posX,posY,cacheD):
    	space = 25
    	x= 0;
    	while x<16:
           #pos
           pos = Label(self, text=str(x), font=("Helvetica", 12), background="gray" ) 
           pos.place(x=posX, y=posY+(space*x))
           #data
           data = Label(self, textvariable=cacheD[x], font=("Helvetica", 12), background="gray" ) 
           data.place(x=130+posX, y=posY+(space*x))	
           x=x+1
    


	

   

        
# root window created. Here, that would be the only window, but
# you can later have windows within windows.
