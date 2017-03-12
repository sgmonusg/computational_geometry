
public class Vertex_DCEL {
	private Point_DCEL point;
	//edge has to random so put incident edge
	private HalfEdge_DCEL edge;
	public Point_DCEL getPoint() {
		return point;
	}
	public void setPoint(Point_DCEL point) {
		this.point = point;
	}
	public HalfEdge_DCEL getEdge() {
		return edge;
	}
	public void setEdge(HalfEdge_DCEL edge) {
		this.edge = edge;
	}
	public Vertex_DCEL(){
		this.setPoint(null);
		this.setEdge(null);
	}
	public Vertex_DCEL(Point_DCEL p){
		this.setPoint(p);
	}
	
	public boolean equals(Vertex_DCEL v){
		boolean temp = ((v.getPoint().equals(this.getPoint())));
		return temp;
	}
	
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append("Vertex[").append(this.getPoint()).append("]");
		return sb.toString();
	}
	public HalfEdge_DCEL findEdgeTo(Vertex_DCEL v){
		if(this.getEdge()!=null){
			if(this.getEdge().getTwin().getOrigin() == v){
				return this.getEdge();
			}
			else{
				HalfEdge_DCEL new_edge= this.getEdge().getTwin().getNext();
				while(new_edge != this.getEdge()){
					if(new_edge.getTwin().getOrigin() == v){
						return new_edge;
					}
					else{
						new_edge = new_edge.getTwin().getNext();
					}
				}
			}
		}
		return null;
	}

}
