/**
 * 
 */

/**
 * @author stark
 *
 */
public class Point {
	private static final double episilon = 0;
	private double x;
	private double y;
	
	public double getXcoordinate(){
		return x;
	}
	public double setXcoordinate(double x){
		this.x = x;
		return x;
	}
	public double getYcoordinate(){
		return y;
	}
	public double setYcoordinate(double y){
		this.y = y;
		return y;
	}
	boolean equals(Point p1){
		boolean e = false;
		if((Math.abs(x-p1.getXcoordinate())<episilon) && (Math.abs(y-p1.getYcoordinate())<episilon)){
			e=true;
		}
		return e;
	}
	double crossProduct(Point p1 , Point p2){
		return (((p1.getXcoordinate()-x)*(p2.getYcoordinate()-y))-((p1.getYcoordinate()-y)*(p2.getXcoordinate()-x)));
	}
	public Point(double x , double y){
		this.x=x;
		this.y=y;
	}

}
