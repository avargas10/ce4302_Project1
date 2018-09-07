
# Simple enough, just import everything from tkinter.
from tkinter import *


# Here, we are creating our class, Window, and inheriting from the Frame
# class. Frame is a class from the tkinter module. (see Lib/tkinter/__init__)
class Window(Frame):
    
    # Define settings upon initialization. Here you can specify
    def __init__(self,num, master=None):
        self.node = num
        self.cpu=0
        self.cacheState=[StringVar() for i in range(16)]
        self.cacheData=[StringVar() for i in range(16)]

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
        
        self.initCpu()
        self.initTextBox()
        #cache1
        self.setImage(1,30,350,"cache"+str(self.node)+".png")
        self.setLabel(1,20,450,"Position")
        #w.text = "pos"
        self.setLabel(1,120,450,"  Data  ")
        self.setLabel(1,220,450,"  State ")
        self.createLine(30,480,self.cacheState,self.cacheData)

    def initCpu(self):
        self.setImage(1,30,30,"cpu"+str(self.node)+".png")


    def initTextBox(self):
        scrollbar = Scrollbar(self, orient=VERTICAL)
        self.cpu = Listbox(self,yscrollcommand=scrollbar.set,height=10,width=25)
        scrollbar.config(command= self.cpu.yview,width=50)
        self.cpu.place(x=30,y=130)
    def client_exit(self):
        exit()

    def setTextBox(self,posX,posY):
        scrollbar = Scrollbar(self)
        scrollbar.pack(side=RIGHT, fill=Y)
        e = Entry(self,textvariable=self.cpu,xscrollcommand=scrollbar)
        e.place(x=posX,y=posY)

    def setImage(self,num,posX,posY,file):
    	photo = PhotoImage(file="assets/"+file)
    	w = Label(self, image=photo)
    	w.photo = photo
    	w.place(x=posX, y=posY)

    def setLabel(self,num,posX,posY,ptext):
        w = Label(self, text="Rouge", fg="red")
        w = Label(self, text=ptext, font=("Helvetica", 16),background="gray")
        w.place(x=posX, y=posY)


    def createLine(self,posX,posY,cacheS,cacheD):
    	space = 25
    	x= 0;
    	while x<16:
           #pos
           pos = Label(self, text=str(x), font=("Helvetica", 12), background="gray" ) 
           pos.place(x=posX, y=posY+(space*x))
           #state
           state = Label(self, textvariable=cacheS[x], font=("Helvetica", 12), background="gray" ) 
           state.place(x=200+posX, y=posY+(space*x))
           #data
           data = Label(self, textvariable=cacheD[x], font=("Helvetica", 12), background="gray" ) 
           data.place(x=100+posX, y=posY+(space*x))	
           x=x+1

    def createEmptyLine(self,posX,posY):
        space = 50
        x= 0;
        while x<16:
           w = Label(self, text="", font=("Helvetica", 12), background="gray" ) 
           w.place(x=posX, y=posY+(space*x))    
           x=x+1
    


	

   

        
# root window created. Here, that would be the only window, but
# you can later have windows within windows.
