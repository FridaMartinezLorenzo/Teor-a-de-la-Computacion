import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Reg{

  public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String cad;

        System.out.print("Introduce cadena: ");
        cad = sc.nextLine();

        Pattern pat = Pattern.compile("\\+?[0-9]{0,3}?" + "[-|\s|.]?\\(?[0-9]{0,2}\\)?[-|\s|.]?[0-9]{0,4}[-|\s|.]?[0-9]{0,4}"
                                      + "\\+?[0-9]{0,3}" + "[-|\s|.]?\\(?[0-9]{0,3}\\)?[-|\s|.]?[0-9]{0,3}[-|\s|.]?[0-9]{0,4}"
                                      + "|[0-9]{3}]");
        Matcher mat = pat.matcher(cad);

        if(mat.matches()){
          System.out.println("cadena valida");
        }else{
          System.out.println("cadena invalida");
        }
  }

}
