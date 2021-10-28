package gui;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;
import javax.swing.JTextField;

public class Fenetre extends JFrame implements ActionListener{
	
	
	LinkedList<Float> patient;
	
	int numbervector;
	LinkedList<Integer> classesindicator;
	LinkedList<String> classesnames;
	int numberclasse;
	String path;
	JPanel p;
	JPanel pan;
	JPanel pan2;
	JPanel pan3;
	JPanel panelprediction;
	JPanel panelutil;
	JTabbedPane paneauinit;
	JLabel lab1;
	JLabel lab2;
	JLabel lab3;
	JLabel lab4;
	JLabel lab5;
	JButton indique;
	JTextField lirenode;
	JTextField tf1;
	JTextField tf2;
	JTextField tf3;
	JTextField tf4;
	JTextField tf5;
	JButton bfinal2;
	JComboBox nodeslist;
	JComboBox utilvectorlist;
	LinkedList<LinkedList<Float>> vectors;
	LinkedList<Integer> vectors_choisis;
	
	LinkedList<LinkedList<Float>> classes;
	JButton b;
	JFileChooser fc;
	File l;
	JButton b1;
	JButton bfinal;
	JButton buttonaddsymptome;
	JButton buttonpredire;
	JButton buttonpurger;
	JPanel chargerindividu;
	JPanel buttons;
public Fenetre(String title,int width,int height) {
	this.numbervector=0;
	
	this.patient=new LinkedList<Float>();
	
	
	this.classesnames=new LinkedList<String>();
	this.vectors_choisis=new LinkedList<Integer>();
	
	
	this.panelutil=new JPanel();
	this.panelutil.setLayout(new BorderLayout());
	this.buttonaddsymptome=new JButton("ajouter un symptome");
	this.buttonpredire=new JButton("predire");
	this.buttonpurger=new JButton("purger");
	this.chargerindividu=new JPanel();
	this.chargerindividu.setLayout(new FlowLayout());
	this.buttons=new JPanel();
	this.buttons.setLayout(new FlowLayout());
	this.buttonpredire.addActionListener(this);
	this.buttonpurger.addActionListener(this);
	this.utilvectorlist=new JComboBox();
	this.chargerindividu.add(this.utilvectorlist);
	this.chargerindividu.add(this.buttonaddsymptome);
	this.buttons.add(this.buttonpredire);
	this.buttons.add(this.buttonpurger);
	this.panelutil.add(this.chargerindividu,BorderLayout.CENTER);
	this.panelutil.add(this.buttons,BorderLayout.SOUTH);
	this.buttonaddsymptome.addActionListener(this);
	
	
	
	
	
	
	
	
	this.classesindicator=new LinkedList<Integer>();
	this.classesnames=new LinkedList<String>();
	this.bfinal2=new JButton("choisir les symptomes");
	this.bfinal2.addActionListener(this);
	
	this.numberclasse=0;
	this.vectors=new LinkedList<LinkedList<Float>>();
	this.classes=new LinkedList<LinkedList<Float>>();
	this.panelprediction=new JPanel();
	this.lab1=new JLabel();
	this.lab2=new JLabel();	
	this.lab3=new JLabel();
	this.lab4=new JLabel();
	this.lab5=new JLabel();
	this.tf1=new JTextField(20);	
	this.tf2=new JTextField(20); 
	this.tf3=new JTextField(20);this.tf4=new JTextField(20);this.tf5=new JTextField(20);
	this.pan3=new JPanel(); 
 
 	
	this.lab1.setText("Walk_length");
	this.lab2.setText("p_parameter");
	this.lab3.setText("q_parameter");
	this.lab4.setText("number_of_walks");
	this.lab5.setText("output_name");
	this.pan3.setLayout(new FlowLayout());
	this.pan3.add(lab1);
	this.pan3.add(tf1);
	this.pan3.add(lab2);
	this.pan3.add(tf2);
	this.pan3.add(lab3);
	this.pan3.add(tf3);
	this.pan3.add(lab4);
	this.pan3.add(tf4);
	this.pan3.add(lab5);
	this.pan3.add(tf5);
	this.nodeslist=new JComboBox();
	
	
	
	
	
	
	
	
	p=new JPanel();
	pan=new JPanel();
	pan2=new JPanel();
	p.setLayout(new BorderLayout());
	this.paneauinit=new JTabbedPane();
	this.paneauinit.addTab("phase entrainement", p);
	this.setContentPane(this.paneauinit);
	this.indique=new JButton("ajouter classe");
	this.indique.addActionListener(this);
	
	
	panelprediction.setLayout(new BorderLayout());
	panelprediction.add(this.nodeslist,BorderLayout.NORTH);
	panelprediction.add(this.indique,BorderLayout.SOUTH);
	panelprediction.add(this.bfinal2,BorderLayout.EAST);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	path=new String("C:\\Users\\pedov\\Gui_for_dev\\gui\\");//"C:\\Users\\pedov\\OneDrive\\Bureau\\dev_app_open_source\\miniprojet\\");
	fc=new JFileChooser(path);
	
	this.setSize(width,height);
	
	//pan.setLayout(new BorderLayout());
	pan.add(fc);
	this.b=new JButton("choisir la base de donnees");
	this.b1=new JButton("lancer le programme");this.b1.addActionListener(this);
	this.bfinal=new JButton("choisir les classe");
	this.bfinal.addActionListener(this);
	this.b.addActionListener(this);
	
	
	pan2.setLayout(new FlowLayout());
	pan2.add(b);pan2.add(b1); pan2.add(bfinal);
	
//this.add(pan2,B);
	p.add(pan,BorderLayout.WEST);
	p.add(pan2,BorderLayout.SOUTH);
	p.add(pan3,BorderLayout.CENTER);
	
	
	
	
	
	this.setVisible(true);
	this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	
	
}
@Override
public void actionPerformed(ActionEvent arg0) {
	// TODO Auto-generated method stub

	
	
	if(arg0.getSource().equals(this.buttonpurger)) {
		float sumdiff=0f;
		float diff=0f;
		
		int max=this.patient.size();
		for (LinkedList<Float> element : this.classes) {
			for(int i=0;i<max;i++) {
			sumdiff=sumdiff+(this.patient.get(i).floatValue()-element.get(i).floatValue())*(this.patient.get(i).floatValue()-element.get(i).floatValue());
			}
			
		}//System.out.println(sumdiff);
		for (LinkedList<Float> element : this.classes) {
			for(int i=0;i<max;i++) {
			diff=diff+(this.patient.get(i).floatValue()-element.get(i).floatValue())*(this.patient.get(i).floatValue()-element.get(i).floatValue());
			}
			//System.out.println(diff);
			System.out.println("ce patient est de classe "+this.classesnames.get(this.classes.indexOf(element))+" a "+(diff/sumdiff)*100);
			diff=0;
			
		}
		
		this.patient.clear();
		this.vectors_choisis.clear();
		
		
		
	}
	
	
	
	
	
	
	if (arg0.getSource().equals(this.buttonpredire)) {
		//float sum=0;
		float i=(new Float(this.vectors_choisis.size())).floatValue();
		//System.out.println(i);
		int max=this.vectors.get(0).size();
		//System.out.println(max);
		for(int j=0;j<max;j++)
			this.patient.add(new Float(0f));
		for(int element : this.vectors_choisis) {
			for(int u=0;u<max;u++) {
				this.patient.set(u,this.patient.get(u).floatValue()+this.vectors.get(element).get(u).floatValue());
			}
				
			
		}
		
		for(int u=0;u<max;u++) {
			this.patient.set(u,this.patient.get(u)/i);
		}
		for(int u=0;u<max;u++) {
			System.out.print(""+this.patient.get(u)+" ");
		}
		
		
		
	}
	
	
	
	
	if(arg0.getSource().equals(this.buttonaddsymptome)) {
		this.vectors_choisis.add(this.utilvectorlist.getSelectedIndex());
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	if(arg0.getSource().equals(this.bfinal2)){
/*
		for (LinkedList<Float> l: this.classes) {
			System.out.println("classe embedded :");
			for(Float f :l) {
				
				System.out.print(f);
				System.out.print(' ');
				
				
			}
			
			System.out.println("this was a class");
			
			
		}
	*/	
		
		try {
			BufferedReader br=new BufferedReader(new FileReader(path+"nodes.txt"));
			BufferedReader br2=new BufferedReader(new FileReader(path+"vectors_.txt"));
			String line;
			String line2;
		int i=0;
		
		while( ((line = br.readLine() ) != null)&& ((line2 = br2.readLine() ) != null) ){
			if(!this.classesindicator.contains(i)) {
				
			this.utilvectorlist.addItem(line);
			String[] tab=line2.split(" ");
			this.vectors.add(new LinkedList<Float>());
			for (String c : tab) {
				this.vectors.get(this.numbervector).add(new Float(c));
			
			}
			
			
			
			
			this.numbervector++;
			i++;
			}
			else i++;
		}br.close();br2.close();
		
		} catch (FileNotFoundException e) {
			
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		this.paneauinit.addTab("tester sur des patient cher user",this.panelutil);
		
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	if(arg0.getSource().equals(this.indique)) {
		
		int classindex=this.nodeslist.getSelectedIndex();
		this.classesindicator.add(classindex);
		this.classesnames.add(this.nodeslist.getSelectedItem().toString());
		int iterator=0;
		this.classes.add(new LinkedList<Float>());
		try {
			BufferedReader br=new BufferedReader(new FileReader(path+"vectors_.txt"));
		String line;
		
		while( (line = br.readLine() ) != null ){
			if(iterator!=classindex) {
				iterator++;
				continue;
			}
			iterator++;
			String[] tab=line.split(" ");
			for (String c : tab) {
				this.classes.get(this.numberclasse).add(new Float(c));
	//	Float x=	new Float("1.0");
				
			}
			
			
		}br.close();
		
		} catch (FileNotFoundException e) {
			
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		this.numberclasse++;
	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	if(arg0.getSource().equals(this.bfinal)) {
		try {
			BufferedReader br=new BufferedReader(new FileReader(path+"nodes.txt"));
		String line;
		while( (line = br.readLine() ) != null ){
			this.nodeslist.addItem(line);
			
			
		}br.close();
		
		} catch (FileNotFoundException e) {
			
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		this.paneauinit.addTab("choix classes",this.panelprediction);
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	String command=new String(" ");
	if(arg0.getSource().equals(this.b))
	this.fc.showOpenDialog(pan);
	if(arg0.getSource().equals(this.b1))  {
		command+=this.tf1.getText()+" ";		
		command+=this.tf2.getText()+" ";
		command+=this.tf3.getText()+" ";
		command+=this.tf5.getText()+" ";
		command+=this.tf4.getText();
		
		
		
		
		
		
		
		
	String g=new String(this.fc.getSelectedFile().getName());
	
	System.out.println("la commande est");
	System.out.println(path+"test.exe "+path+g);//" >>" +path+"redirected.txt"
	
	//System.out.println(this.fc.getSelectedFile().getName());
	try {
		Runtime r=Runtime.getRuntime();
		Process p =r.exec(path+"test.exe "+path+g+command  );
	//	  java.io.BufferedReader out = new java.io.BufferedReader( new java.io.InputStreamReader( p.getInputStream() ) );
		InputStream inp = p.getInputStream();
		InputStreamReader isr = new InputStreamReader(inp);
		BufferedReader br = new BufferedReader(isr);
		
		
		String line = null ; 
		
		System.out.println("Error : ");
		while( (line = br.readLine() ) != null )
			System.out.println(line);
		br.close();
		//OutputStream out=p.getOutputStream();
		//OutputStreamWriter o=new OutputStreamWriter(out);
		//String a;
	//	o.write(a);
		
		
		p.waitFor();
		System.out.println("le programme c a enfin fini");
	//	Process	q= r.exec("C:\\Users\\pedov\\keras\\Anaconda3\\Scripts\\activate.bat");
	//	q.getOutputStream().write(r.exec("python.exe " + path+  "embedding.py"   ).getInputStream().read());
	//	q =;//C:\\Users\\pedov\\keras\\Anaconda3\\
	//	q.waitFor();
	//	System.out.println("le programme python a enfin fini");
		
	} catch (IOException e) {
		// TODO Auto-generated catch block
		System.out.println("probelem");
		e.printStackTrace();
	} catch (Exception e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	
	
	
	
	
	
	try {
		Runtime r=Runtime.getRuntime();
		Process p =r.exec(path+"lanceur.exe "  );
		InputStream inp = p.getInputStream();
		InputStreamReader isr = new InputStreamReader(inp);
		BufferedReader br = new BufferedReader(isr);
		
		
		String line = null ; 
		
		System.out.println("Error : ");
		while( (line = br.readLine() ) != null )
			System.out.println(line);
		
		
		p.waitFor();
		System.out.println("le programme c a enfin fini");
		
	} catch (IOException e) {
		// TODO Auto-generated catch block
		System.out.println("probelem");
		e.printStackTrace();
	} catch (Exception e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	










	}






}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
	
	
	

