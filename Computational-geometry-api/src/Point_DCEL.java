
public class Point_DCEL {
	private enum Side{
		LEFT , RIGHT , UNKNOWN
	}
	private enum Type{
		CONVEX , REFLEX , UNKNOWN
	}
	private double x;
	private double y;
	private Side side;
	private Type type;
	private int pos;


	public Point_DCEL (double x  , double y){
		this.setX(x);
		this.setY(y);
		this.setSide(Side.UNKNOWN);
		this.setType(Type.UNKNOWN);
		this.setPos(-1);
	}


	public double getX() {
		return x;
	}


	public void setX(double x) {
		this.x = x;
	}


	public double getY() {
		return y;
	}


	public void setY(double y) {
		this.y = y;
	}


	public Side getSide() {
		return side;
	}


	public void setSide(Side side) {
		this.side = side;
	}


	public Type getType() {
		return type;
	}


	public void setType(Type type) {
		this.type = type;
	}


	public int getPos() {
		return pos;
	}


	public void setPos(int pos) {
		this.pos = pos;
	}
	public boolean equals(Point_DCEL p){
		Boolean temp = (p.getX() == this.getX() && p.getY() ==this.getY());
		return temp;
	}
	
	public String toString(){
		return "("+this.getX()+","+this.getY()+","+this.getType()+")";
	}
	
	public int compareTo(Point_DCEL p){
		if(this.getY()<p.getY()){
			return -1;
		}
		else if (this.getY()==p.getY()){
			if(this.getX()<p.getX()){
				return -1;
			}
			else if(this.getX()==p.getX()){
				return 0;
			}
			else{
				return 1;
			}
		}
		else{
			return 1;
		}
	}
	
	public Point_DCEL sum(Point_DCEL p){
		Point_DCEL p1 = new Point_DCEL(this.getX()+p.getX() , this.getY()+p.getY());
		return p1;
	}
	
	public Point_DCEL difference(Point_DCEL p){
		Point_DCEL p1 = new Point_DCEL(this.getX()-p.getX() , this.getY()-p.getY());
		return p1;
	}
	
	public double dot(Point_DCEL p){
		double temp = this.getX()*p.getX()+this.getY()*p.getY();
		return temp;
	}
	public double cross(Point_DCEL a , Point_DCEL b , Point_DCEL c){
		double temp =0;
		temp = (b.getX()-a.getX())*(c.getY()-a.getY());
		temp = temp-((b.getY()-a.getY())*(c.getX()-a.getX()));
		return temp;
	}
	
	public boolean isBelow(Point p){
		if(this.getY()-p.getYcoordinate()<0.0){
			return true;
		}
		else{
			return false;
		}
	}
	public void calculateType(Point_DCEL prev , Point_DCEL next){
		double cross = this.cross(prev, this, next);
		if(cross >0.0){
			this.setType(Type.CONVEX);
		}
		else{
			this.setType(Type.REFLEX);
		}
	}
}