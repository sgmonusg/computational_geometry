/**
 * 
 */

/**
 * @author stark
 *
 */
public class ConvexHull {
	private Data input;
	private Data output;
	public Data getInput() {
		return input;
	}
	public void setInput(Data input) {
		this.input = input;
	}
	public Data getOutput() {
		return output;
	}
	public void setOutput(Data output) {
		this.output = output;
	}
	public ConvexHull(Data in){
		setInput(in);
	}
	public void grahamScan(){
		int N = getInput().getSize();
		if(N < 3){
			return;
		}
		Data new_data = getOutput();
		new_data.setSize(0);
		setOutput(new_data);
		Point min_point = getInput().getPointfromList(0);
		@SuppressWarnings("unused")
		int min_idx =0;
		for (int i=0;i<N ; i++){
			Point current = getInput().getPointfromList(i);
			if((current.getYcoordinate() < min_point.getYcoordinate())||(current.getYcoordinate() < min_point.getYcoordinate() && current.getXcoordinate() < min_point.getXcoordinate())){
				min_point= current;
				min_idx =i;
			}
		}
		new_data=getOutput();
		new_data.addPoint(min_point);
		setOutput(new_data);
		
		
	}

}
