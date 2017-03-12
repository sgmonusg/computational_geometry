import java.util.ArrayList;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author Sagar Gupta
 *
 */
public class Data {
	private int N;
	
	public int getN() {
		return N;
	}
	
	public void setN(int n) {
		N = n;
	}
	
	private ArrayList <Point> list_of_points = new ArrayList<Point> ();
	
	public ArrayList <Point> getList_of_points() {
		return list_of_points;
	}
	
	public void setList_of_points(ArrayList <Point> list_of_points) {
		this.list_of_points = list_of_points;
	}
	
	public ArrayList <Point> addPoint(Point p1){
		ArrayList <Point> new_list = new ArrayList <Point> ();
		new_list = getList_of_points();
		new_list.add(p1);
		setList_of_points(new_list);
		return list_of_points;
		
	}
	
	Point getPointfromList(int idx){
		return(getList_of_points().get(idx));
	}
	
	int getSize(){
		return getN();
	}
	
	void setValueinList(int idx , Point p1){
		ArrayList<Point> new_list = getList_of_points();
		new_list.add(idx, p1);
		setList_of_points(new_list);
	}
	
	//TODO-sagar
	void setSize(int x){
		setN(x);
		
	}
	
	void display(){
		for(int i=0;i<getN();i++){
			System.out.println(getList_of_points().get(i).getXcoordinate()+" "+getList_of_points().get(i).getYcoordinate());
		}
	}
	
	Data(){
		setN(0);
	}
	
	Data(Point arg_points[] , int size){
		setN(size);
		for(int i=0 ;i< N ; i++){
			addPoint(arg_points[i]);
		}
	}
	
	void getinput(){
		System.out.println("Enter the number of points");
		Scanner sc= new Scanner(System.in);
		setN(sc.nextInt());
		System.out.println("Enter"+getN()+"points fisrt x then y");
		for(int i=0 ;i<getN();i++){
			double x,y ;
			x= sc.nextDouble();
			y=sc.nextDouble();
			Point pi = new Point(x, y);
			addPoint(pi);
		}
		sc.close();
	}
	void addPointtolist(Point p1){
		if(getN()<list_of_points.size()){
			setN(getN()+1);
			addPoint(p1);
		}
	}
	
	void swap(int idx1 , int idx2){
		Point p1 = getList_of_points().get(idx1);
		ArrayList<Point> new_list = getList_of_points();
		new_list.add(idx1, getList_of_points().get(idx2));
		new_list.add(idx2, p1);
	}
	
	
}