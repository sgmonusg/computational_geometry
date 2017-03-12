/**
 * 
 */

/**
 * @author stark
 *
 */

public class HalfEdge_DCEL {
	
	public enum EdgeType{
		VERTICAL , HORIZONTAL , UNKNOWN
	}
	
	private Vertex_DCEL origin;
	private Face_DCEL incident_face;
	private HalfEdge_DCEL next;
	private HalfEdge_DCEL twin;
	private EdgeType type;
	private boolean isArtificial;
	public HalfEdge_DCEL next() {
		// TODO Auto-generated method stub
		return null;
	}

	public Vertex_DCEL getOrigin() {
		return origin;
	}

	public void setOrigin(Vertex_DCEL origin) {
		this.origin = origin;
	}

	public Face_DCEL getIncident_face() {
		return incident_face;
	}

	public void setIncident_face(Face_DCEL incident_face) {
		this.incident_face = incident_face;
	}

	public HalfEdge_DCEL getNext() {
		return next;
	}

	public void setNext(HalfEdge_DCEL next) {
		this.next = next;
	}

	public HalfEdge_DCEL getTwin() {
		return twin;
	}

	public void setTwin(HalfEdge_DCEL twin) {
		this.twin = twin;
	}

	public EdgeType getType() {
		return type;
	}

	public void setType(EdgeType type) {
		this.type = type;
	}
	public HalfEdge_DCEL(HalfEdge_DCEL twin , boolean isArtificial , EdgeType type , Vertex_DCEL origin){
		this.setTwin(twin);
		this.setType(type);
		this.setOrigin(origin);
		this.setArtificial(isArtificial);
	}
	public HalfEdge_DCEL(HalfEdge_DCEL e){
		this.setOrigin(e.getOrigin());
		this.setIncident_face(e.getIncident_face());
		this.setNext(e.getNext());
		this.setType(e.getType());
		this.setTwin(e.getTwin());
	}
	public void calculateType(){
		Point_DCEL p = this.getTwin().getOrigin().getPoint();
		if(this.getOrigin().getPoint().getX()==p.getX()){
			this.setType(EdgeType.HORIZONTAL);
		}
		else if(this.getOrigin().getPoint().getY()==p.getY()){
			this.setType(EdgeType.VERTICAL);
		}
		else{
			this.setType(EdgeType.UNKNOWN);
		}
	}
	public boolean equal(HalfEdge_DCEL e){
		boolean temp = e.getOrigin().equals(this.getOrigin()) && e.getTwin().getOrigin().equals(this.getTwin().getOrigin());
		return temp;
	}
	// edge may be twin or same
	public boolean sameEdge(HalfEdge_DCEL e){
		boolean temp = e.equal(this);
		boolean temp1 = e.equal(this.twin);
		if(temp || temp1){
			return true;
		}
		else{
			return false;
		}
	}

	public boolean isArtificial() {
		return isArtificial;
	}

	public void setArtificial(boolean isArtificial) {
		this.isArtificial = isArtificial;
	}
}
