import java.util.*;

class Repo {
    private static ArrayList<String> missions = new ArrayList<String>();
    private static boolean k = true;

    public Repo(String items) {
        String[] itemss = items.split("\\s+");
        for(String item : itemss)
            missions.add(item);
    }  

    int getSize() {
        return missions.size();
    }

    public synchronized void give1() {
        if(k == false) {
            try {
                this.wait();
            }
            catch(Exception e) {
                e.printStackTrace();
            }
        }
        else {
            System.out.println(Thread.currentThread().getName() + " finish " + missions.get(0));
            missions.remove(0);
            k = false;
            this.notify();
        }
    }

    public synchronized void give2() {
        if(k == true) {
            try {
                this.wait();
            }
            catch(Exception e) {
                e.printStackTrace();
            }
        }
        else {
            System.out.println(Thread.currentThread().getName()+ " finish " + missions.get(0));
            missions.remove(0);
            k = true;
            this.notify();
        }
    }
}

class Worker1 implements Runnable {
    Repo repo;
    Worker1(Repo repo) {
        this.repo = repo;
    }

    public void run() {
        while(true) {
            if(repo.getSize() == 0) break;
            repo.give1();
        }
    }
}

class Worker2 implements Runnable {
    Repo repo;
    Worker2(Repo repo) {
        this.repo = repo;
    }

    public void run() {
        while(true) {
            if(repo.getSize() == 0) break;
            repo.give2();
        }
    }
}