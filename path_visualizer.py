#This is a visualizer script to help design a proper path planning algortihm with a good enemy avoidance implementation
#All that needs to be done to simulate a path is to create a list of xy points like the example bellow and the call the simulate_route function as seen bellow

import tkinter as tk
from PIL import Image, ImageTk

path=[1,1,2,2]
desired_width = 1200 
desired_height = 800
scaling = 4


def main():
    root = tk.Tk()
    root.title("HR Path Visualizer")

    #Choose either of the paths bellow. Former is this year's playmat and latter is last year's playmat
    # image_path = r"C:\Users\gkkti\Documents\python\playmat_2025_FINAL.png"
    image_path=r"vinyle_table_2025_FINAL_V1.png"

    #Scalling stuff
    bg_image = Image.open(image_path)
    bg_image = bg_image.resize((desired_width, desired_height), Image.LANCZOS)  # LANCZOS cause anti aliasing is depreceated or some dumb shit
    bg_photo = ImageTk.PhotoImage(bg_image)

    #Create the play area
    canvas = tk.Canvas(root, width=desired_width, height=desired_height)
    canvas.pack(fill="both", expand=True)

    #Adds the image as a background to the canvas
    canvas.create_image(0, 0, anchor="nw", image=bg_photo)


    draw_array(scaling,canvas)

    #for i in range(75,125):
    #    draw_obstacle(150,i,1,scaling,canvas)
    #draw_obstacle(150,150,12,scaling,canvas)
    #draw_obstacle(150,50,12,scaling,canvas)
    #draw_obstacle(100,70,12,scaling,canvas)
    #draw_obstacle(100,130,12,scaling,canvas)
    #draw_obstacle(200,70,12,scaling,canvas)
    #draw_obstacle(200,130,12,scaling,canvas)

    simulate_route(path,scaling,canvas)

    root.mainloop()

def draw_array(scaling,canvas):
    array = []
    for i in range(0,len(array),2):
        draw_obstacle(array[i],array[i+1],1,scaling,canvas)
    

def draw_obstacle(x, y, size, scaling, canvas):
    y=200-y
    x0 = x*scaling - size*scaling
    y0 = y*scaling - size*scaling
    x1 = x*scaling + size*scaling
    y1 = y*scaling + size*scaling
    return canvas.create_oval(x0, y0, x1, y1, outline='black',fill='red', tags='deletables')

def draw_path_start(x, y, scaling, canvas):
    #To change from the old to the new coordinates system
    #The abscissa needs no change but the ordinate needs to be flipped with the bellow formula
    y=200-y 
    x0 = x*scaling - 10*scaling
    y0 = y*scaling - 10*scaling
    x1 = x*scaling + 10*scaling
    y1 = y*scaling + 10*scaling
    canvas.create_oval(x0, y0, x1, y1, outline='blue', tags='deletables')


    x0 = x*scaling - 10*scaling
    y0 = y*scaling - 10*scaling
    x1 = x*scaling + 10*scaling
    y1 = y*scaling + 10*scaling
    x2 = x*scaling - 10*scaling
    y2 = y*scaling + 10*scaling
    x3 = x*scaling + 10*scaling
    y3 = y*scaling - 10*scaling

    canvas.create_line(x0+12,y0+12,x1-12,y1-12,fill='blue', tags='deletables')
    canvas.create_line(x2+12,y2-12,x3-12,y3+12,fill='blue', tags='deletables')


def draw_path_end(x, y, scaling, canvas):
    y=200-y
    half_side = 8*scaling
    x1 = x*scaling - half_side
    y1 = y*scaling - half_side
    x2 = x*scaling + half_side
    y2 = y*scaling + half_side
    canvas.create_rectangle(x1, y1, x2, y2, outline='blue', tags='deletables')

    x0 = x*scaling - 10*scaling
    y0 = y*scaling - 10*scaling
    x1 = x*scaling + 10*scaling
    y1 = y*scaling + 10*scaling
    x2 = x*scaling - 10*scaling
    y2 = y*scaling + 10*scaling
    x3 = x*scaling + 10*scaling
    y3 = y*scaling - 10*scaling

    canvas.create_line(x0+3*scaling,y0+3*scaling,x1-3*scaling,y1-3*scaling,fill='blue', tags='deletables')
    canvas.create_line(x2+3*scaling,y2-3*scaling,x3-3*scaling,y3+3*scaling,fill='blue', tags='deletables')


def draw_path_midpoint(x, y, scaling, canvas):
    y=200-y
    x0 = x*scaling - scaling
    y0 = y*scaling - scaling
    x1 = x*scaling + scaling
    y1 = y*scaling + scaling
    return canvas.create_oval(x0, y0, x1, y1, outline='blue',fill='blue', tags='deletables')

def simulate_route(path, scaling, canvas):

    draw_path_start(path[0],path[1], scaling, canvas)
    # draw_path_midpoint(path[0],path[1],scaling,canvas)
    while path:
        canvas.create_line(path[0]*scaling,(200-path[1])*scaling,path[2]*scaling,(200-path[3])*scaling,fill='blue', tags='deletables')
        path.remove(path[0]),path.remove(path[0])
        if len(path)==2:
            # draw_path_midpoint(path[0],path[1],scaling,canvas)
            draw_path_end(path[0],path[1],scaling,canvas)
            path.remove(path[0]),path.remove(path[0])
            break
        else:
            draw_path_midpoint(path[0],path[1],scaling,canvas)


if __name__ == "__main__":
    main()
