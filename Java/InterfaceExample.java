//package Java;

interface example {
	public String getName();
	public void setName(String name);
}

public class InterfaceExample implements example{
	private String name;
	
	InterfaceExample(String name){
		this.name = name;
	}
	@Override
	public String getName() {
		return this.name;
	}

	@Override
	public void setName(String name) {
		this.name = name;
	}
	
	public static void main(String[] args) {
		InterfaceExample exam = new InterfaceExample("jeff");
		
		System.out.println(exam.getName());
	}
}
