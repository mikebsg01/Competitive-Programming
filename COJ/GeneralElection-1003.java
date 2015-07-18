import java.util.Scanner;

public class Main {

   
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
	    int t, n, m;
        
        t = s.nextInt();
        
        for(int i=0;i<t;i++){
            
            n = s.nextInt();
            m = s.nextInt();
            int[] candidatos = new int[n];
            int aux = 0;
            
            for(int a=0;a<m;a++){
                for(int b=0;b<n;b++){
                    aux = s.nextInt();
                    candidatos[b] += aux;
                }
            }
            int aux1 = 0, mayor = 0, index = 0;
            for(int x=0;x<n;x++){
                if(x==0){
                    mayor = candidatos[x];
                    index = 0;
                }
                if(x!=0){
                     if(candidatos[x]>mayor){
                          mayor = candidatos[x];
                          index = x;
                     }
                }
            }
            System.out.println(index+1);
        }
        
    }
    
}
