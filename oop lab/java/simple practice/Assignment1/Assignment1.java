public class Assignment1 {

     static double spb=7.0;             //spb = second per birth;
     static int spd=13;            //spd = second per death;
     static int spm=45;            //spm = second per migration;
    private static long  pop=312032486;  //pop =current population
    private static int sec=365*24*60*60;    //sec=second in one year
    public static long project_population(){
        pop=pop+(int)(sec/spb)+(sec/spm)-(sec/spd);
        return pop;
}
    public static void main(String[] args) {
        int i;
        for(i=0;i<5;i++){
            System.out.println("population is "+(i+1)+" year is "+project_population());
        }
    }
    
}