#include <iostream>
#include "Graph.h"
#include "Simple_window.h"
#include <fstream>
#include <sstream>
#include <cfloat>

using namespace std;
using namespace Graph_lib;

const double pi=3.14159;

double Rect_Area(double x,double y){return x*y;}
double Ell_Area(double a, double b){return pi*a*b;}

inline void error_mine(const string& s) {
    throw runtime_error(s);}

int main() {
    try {
        Simple_window win(Point(100, 100), 800, 600, "Project 1");
        string line;
        string buff;
        int line_num = 1;
        string info_part;
        vector<string> info;
        vector<string> temp;

        ifstream file1("shapes.txt");
        ifstream file2("shapes.txt");

        while(getline(file1,line)){
            temp.clear();
            stringstream ss(line);
            while (ss>>buff)
                temp.push_back(buff);
            if(temp.size()!=6)
                error_mine("Invalid shape information on line "+to_string(line_num));
            ++line_num;

        }

        line_num=1;
        while (file2 >> info_part) {
            info.push_back(info_part);
        }

        int shape_type = 0;
        int shape_color = 1;
        int shape_x1 = 2;
        int shape_y1 = 3;
        int shape_x2 = 4;
        int shape_y2 = 5;
        double largest=0;
        double smallest= DBL_MAX;
        string largest_string;
        string smallest_string;
        double x1;
        double y1;
        double x2;
        double y2;
        Vector_ref<Rectangle> rect_outcome;
        vector<string> rect_color;
        Vector_ref<Ellipse> ell_outcome;
        vector<string> ell_color;


        for (int i = 0; i < (info.size() / 6); ++i) {
           try {
               x1 = stod(info[shape_x1]);
               y1 = stod(info[shape_y1]);
               x2 = stod(info[shape_x2]);
               y2 = stod(info[shape_y2]);
           }
            catch (exception &e){
                error_mine("Invalid shape information on line "+to_string(line_num));
            }

            double base;
            double height;

            if (info[shape_type] == "rectangle") {
                base=x2-x1;
                height=y2-y1;
                rect_outcome.push_back(new Rectangle (Point(x1, y1), base, height));
                if (info[shape_color] == "red")
                    rect_color.push_back("red");
                else if (info[shape_color] == "blue")
                    rect_color.push_back("blue");
               else if (info[shape_color] == "green")
                    rect_color.push_back("green");
                else if (info[shape_color] == "yellow")
                    rect_color.push_back("yellow");
                else if (info[shape_color] == "white")
                    rect_color.push_back("white");
                else if (info[shape_color] == "black")
                    rect_color.push_back("black");
                else if (info[shape_color] == "magenta")
                    rect_color.push_back("magenta");
                else if (info[shape_color] == "cyan")
                    rect_color.push_back("cyan");
                else if (info[shape_color] == "dark_red")
                    rect_color.push_back("dark_red");
                else if (info[shape_color] == "dark_green")
                    rect_color.push_back("dark_green");
                else if (info[shape_color] == "dark_yellow")
                    rect_color.push_back("dark_yellow");
                else if (info[shape_color] == "dark_blue")
                    rect_color.push_back("dark_blue");
                else if (info[shape_color] == "dark_magenta")
                    rect_color.push_back("dark_magenta");
                else if (info[shape_color] == "dark_cyan")
                    rect_color.push_back("dark_cyan");
                else
                    error_mine("Invalid shape information on line "+to_string(line_num));

                if(Rect_Area(base,height)>largest){
                    largest=Rect_Area(base,height);
                    largest_string="Largest shape was a rectangle with an area of "+to_string(largest);
                }
                if(Rect_Area(base,height)<smallest){
                    smallest=Rect_Area(base,height);
                    smallest_string="Smallest shape was a rectangle with an area of "+to_string(smallest);
                }
            }

            else if (info[shape_type] == "ellipse") {
                base=x2/2;
                height=y2/2;
                ell_outcome.push_back(new Ellipse (Point(x1, y1), base, height));
                if (info[shape_color] == "red")
                    ell_color.push_back("red");
                else if (info[shape_color] == "blue")
                    ell_color.push_back("blue");
                else if (info[shape_color] == "green")
                    ell_color.push_back("green");
                else if (info[shape_color] == "yellow")
                    ell_color.push_back("yellow");
                else if (info[shape_color] == "white")
                    ell_color.push_back("white");
                else if (info[shape_color] == "black")
                    ell_color.push_back("black");
                else if (info[shape_color] == "magenta")
                    ell_color.push_back("magenta");
                else if (info[shape_color] == "cyan")
                    ell_color.push_back("cyan");
                else if (info[shape_color] == "dark_red")
                    ell_color.push_back("dark_red");
                else if (info[shape_color] == "dark_green")
                    ell_color.push_back("dark_green");
                else if (info[shape_color] == "dark_yellow")
                    ell_color.push_back("dark_yellow");
                else if (info[shape_color] == "dark_blue")
                    ell_color.push_back("dark_blue");
                else if (info[shape_color] == "dark_magenta")
                    ell_color.push_back("dark_magenta");
                else if (info[shape_color] == "dark_cyan")
                    ell_color.push_back("dark_cyan");
                else
                    error_mine("Invalid shape information on line "+to_string(line_num));

                if(Ell_Area(base,height)>largest){
                    largest=Ell_Area(base,height);
                    largest_string="Largest shape was an ellipse with an area of "+to_string(largest);
                }
                if(Ell_Area(base,height)<smallest){
                    smallest=Ell_Area(base,height);
                    smallest_string="Smallest shape was an ellipse with an area of "+to_string(smallest);
                }
            }

            else error_mine("Invalid shape information on line "+to_string(line_num));

            shape_type = shape_type + 6;
            shape_color = shape_color + 6;
            shape_x1 = shape_x1 + 6;
            shape_y1 = shape_y1 + 6;
            shape_x2 = shape_x2 + 6;
            shape_y2 = shape_y2 + 6;
            ++line_num;
        }
        Text largest_area(Point(50,25),largest_string);
        Text smallest_area(Point(50,50),smallest_string);
        win.attach(largest_area);
        win.attach(smallest_area);
        for(int j=0;j<rect_outcome.size();++j) {
            if(rect_color[j]=="red") rect_outcome[j].set_color(Color::red);
            else if(rect_color[j]=="blue") rect_outcome[j].set_color(Color::blue);
            else if(rect_color[j]=="green") rect_outcome[j].set_color(Color::green);
            else if(rect_color[j]=="yellow") rect_outcome[j].set_color(Color::yellow);
            else if(rect_color[j]=="white") rect_outcome[j].set_color(Color::white);
            else if(rect_color[j]=="black") rect_outcome[j].set_color(Color::black);
            else if(rect_color[j]=="magenta") rect_outcome[j].set_color(Color::magenta);
            else if(rect_color[j]=="cyan") rect_outcome[j].set_color(Color::cyan);
            else if(rect_color[j]=="dark_red") rect_outcome[j].set_color(Color::dark_red);
            else if(rect_color[j]=="dark_green") rect_outcome[j].set_color(Color::dark_green);
            else if(rect_color[j]=="dark_yellow") rect_outcome[j].set_color(Color::dark_yellow);
            else if(rect_color[j]=="dark_blue") rect_outcome[j].set_color(Color::dark_blue);
            else if(rect_color[j]=="dark_magenta") rect_outcome[j].set_color(Color::dark_magenta);
            else if(rect_color[j]=="dark_cyan") rect_outcome[j].set_color(Color::dark_cyan);
            win.attach(rect_outcome[j]);
        }
        for(int j=0;j<ell_outcome.size();++j){
            if(ell_color[j]=="red") ell_outcome[j].set_color(Color::red);
            else if(ell_color[j]=="blue") ell_outcome[j].set_color(Color::blue);
            else if(ell_color[j]=="green") ell_outcome[j].set_color(Color::green);
            else if(ell_color[j]=="yellow") ell_outcome[j].set_color(Color::yellow);
            else if(ell_color[j]=="white") ell_outcome[j].set_color(Color::white);
            else if(ell_color[j]=="black") ell_outcome[j].set_color(Color::black);
            else if(ell_color[j]=="magenta") ell_outcome[j].set_color(Color::magenta);
            else if(ell_color[j]=="cyan") ell_outcome[j].set_color(Color::cyan);
            else if(ell_color[j]=="dark_red") ell_outcome[j].set_color(Color::dark_red);
            else if(ell_color[j]=="dark_green") ell_outcome[j].set_color(Color::dark_green);
            else if(ell_color[j]=="dark_yellow") ell_outcome[j].set_color(Color::dark_yellow);
            else if(ell_color[j]=="dark_blue") ell_outcome[j].set_color(Color::dark_blue);
            else if(ell_color[j]=="dark_magenta") ell_outcome[j].set_color(Color::dark_magenta);
            else if(ell_color[j]=="dark_cyan") ell_outcome[j].set_color(Color::dark_cyan);
            win.attach(ell_outcome[j]);
        }
        win.wait_for_button();
    }

    catch(exception& e){
        string err= e.what();
        Simple_window win(Point(100, 100), 800, 600, "Project 1");
        Text message(Point(50,50),err);
        win.attach(message);
        win.wait_for_button();
    }
}

/*create a vector of pointers and store information at that location
 * then reference those pointers
 * Delete memory after the process is done
 *
 * smart pointers?*/