// DEMONSTRATE HOW TO MAKE A SCROLLABLE "CANVAS" DRAWING OF AN 'X'
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>
#include <FL/fl_draw.H>
// SCROLLABLE CANVAS EXAMPLE -- JUST DRAWS AN 'X'
class MyCanvas : public Fl_Widget {
public:
     MyCanvas(int X,int Y,int W,int H,const char*L=0) : Fl_Widget(X,Y,W,H,L) {
     }
     void draw() {
         // DRAW BG
         fl_color(color());
         fl_rectf(x(),y(),w(),h());
         // DRAW 'X' OVER BG
         //   Do your graphics here..
         //
         int x1=x(), y1=y();               // Fl_Scroll works by changing our widget's x() and y(),
         int x2=x()+w()-1, y2=y()+h()-1;   // so take these into account for our drawing coordinates  
         fl_color(FL_BLACK);
         fl_line(x1,y1,x2,y2);
         fl_line(x1,y2,x2,y1);
     }
};
int main() {
     Fl_Double_Window win(200,200);
       Fl_Scroll scroll(0,0,200,200);
         MyCanvas canvas(0,0,350,350);     // purposely make drawing area larger than scroll
       scroll.end();
     win.end();
     win.resizable(canvas);
     win.show();
     return(Fl::run());
}
   