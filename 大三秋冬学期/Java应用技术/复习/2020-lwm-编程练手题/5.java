class WorkerList{
	Worker readInWorker() {
		Scanner sc=new Scanner(System.in);
		Worker a= new Worker();
		String nam=sc.next();
		double sal=sc.nextDouble();
		a.setSalary(sal);
		a.setName(nam);
		sc.close();
		return a;
	}
	List<Worker> constructWorkerList()
	{
		Scanner sc=new Scanner(System.in);
		List<Worker> list=new ArrayList<Worker>();
		int n=sc.nextInt();
		//Worker w=new Worker();
		
		String nc;
		double sa;
		for(int i=0;i<n;i++)
		{
			Worker w=new Worker();
			//w=readInWorker();
			nc=sc.next();
			sa=sc.nextDouble();
			w.setName(nc);
			w.setSalary(sa);
			list.add(w);
			
		}
		sc.close();
		return list;
	}
	double computeTotalSalary(List<Worker> list)
	{
		double sum=0;
		for(int i=0;i<list.size();i++)
		{
			sum=sum+list.get(i).getSalary();
		}
		return sum;
	}
}

