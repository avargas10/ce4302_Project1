from tkinter import *
import dataPrinter
import memoryPrinter
import time
import ntpath
import json
import sys
import os
from threading import Thread
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

def lastLine(fileName):
	with open(fileName, 'r') as f:
	    lines = f.read().splitlines()
	    last_line = lines[-1]
	    return last_line




class Watcher(Thread):
    DIRECTORY_TO_WATCH = "../Data/"

    def __init__(self,num,Window):
    	Thread.__init__(self)
    	self.window = Window
    	self.num = num
    	self.DIRECTORY_TO_WATCH = self.DIRECTORY_TO_WATCH+"node"+str(num)
    	self.observer = Observer()

    def run(self):
        event_handler = Handler(self.window,self.num)
        self.observer.schedule(event_handler, self.DIRECTORY_TO_WATCH, recursive=True)
        self.observer.start()
        try:
            while True:
            	
                time.sleep(2)
        except:
            self.observer.stop()
            print ("Error")

        self.observer.join()


class Handler(FileSystemEventHandler):
	def __init__(self,Window,num):
		self.window = Window
		self.num = num
	def on_any_event(self,event):
		if event.is_directory:
			return None
		elif event.event_type == 'modified':
		    head, tail = os.path.split(event.src_path)
		    var = lastLine(event.src_path)
		    if(self.num=="5"):
		    	self.handleMem(var)
		    else:
		    	if(tail=="cpu.txt"):
		    		self.handleCpu(var)	
		    	elif(tail=="cache.txt"):
		    		self.handleCache(var)
		    
			
	def handleCache(self,j):
		res = json.loads(j)
		for x in res:
			state = x["State"]
			if(state==0):
				state = "Invalid"
			elif(state==1):
				state = "Shared"
			elif(state==2):
				state = "Modified"

			pos = int(x["Position"])
			data = x["Data"]
			self.window.cacheState[pos].set(state)
			self.window.cacheData[pos].set("CPU "+str(data))
	
	def handleMem(self,j):
		res = json.loads(j)
		for x in res:
			pos = int(x["Position"])
			data = x["Data"]
			self.window.data[pos].set("CPU "+str(data))

	def handleCpu(self,j):
		res = json.loads(j)
		action = res["action"]
		if(action=="0"):
			action = "Reading"
		elif(action=="1"):
			action = "Writing"
		elif(action=="2"):
			action = "Processing"

		position = res["position"]
		data = res["data"]
		message = action+" in "+position+" Data: "+data
		self.window.cpu.insert(END,message)







if __name__ == '__main__':	
	
	root = Tk()
	root.geometry("300x900")
	#creation of an instance
	app = 0
	if(sys.argv[1]=="5"):
		app = memoryPrinter.MemoryWindow(sys.argv[1],root)
	else:
		app = dataPrinter.Window(sys.argv[1],root)
	w = Watcher(sys.argv[1],app)
	w.start()
	#cpu 
	#mainloop 
	root.mainloop()  
"""
python3 GUI/dataAnalyzer.py 1&  python3 GUI/dataAnalyzer.py 2 &  python3 GUI/dataAnalyzer.py 5 &  python3 GUI/dataAnalyzer.py 4 &  python3 GUI/dataAnalyzer.py 3 build/./ce4302_Project1
"""