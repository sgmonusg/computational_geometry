
public class Face_DCEL {
	private HalfEdge_DCEL edge ;
	
	public  Face_DCEL(){
		this.setEdge(null);
	}
	public  Face_DCEL(HalfEdge_DCEL e){
		this.setEdge(e);
	}

	public HalfEdge_DCEL getEdge() {
		return edge;
	}

	public void setEdge(HalfEdge_DCEL edge) {
		this.edge = edge;
	}
	
	public int getEdgeCount(){
		HalfEdge_DCEL edge = this.getEdge();
		int count =0;
		if(edge != null){
			count++;
			edge =edge.next();
		}
		return count;
	}

}
