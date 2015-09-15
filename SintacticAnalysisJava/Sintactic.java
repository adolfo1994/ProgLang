import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


enum CharClass{
    LETTER(0),
    DIGIT(1),
    FLOAT_SEPARATOR(2),
    INVALID (98),
    UNKOWN (99);

    private final Integer value;
    
    CharClass(Integer value){
        this.value = value;
    }

    public Integer getValue(){
        return this.value;
    }
}

enum TokenCode{
    INT_LIT(10),
    FLOAT_LIT(11),
    IDENT(12),
    ASSIGN_OP (20),
    ADD_OP (21),
    SUB_OP (22),
    MULT_OP (23),
    DIV_OP (23),
    LEFT_PAREN (25),
    RIGHT_PAREN (26);

    private final Integer value;
    
    TokenCode(Integer value){
        this.value = value;
    }

    public Integer getValue(){
        return this.value;
    }
}
class ReadFile{
    private String path;
    private BufferedReader br;

    ReadFile(String path){
        this.path = path;
        try{
            br = new BufferedReader(new FileReader(path));
        }catch(IOException e){
            e.printStackTrace();
        }
    }

    Character nextChar(){
        int read;
        try{
            if ((read = br.read()) != -1){
                return (char) read;
            }else{
                return (char) -1; 
            }
        } catch(IOException ex){
            ex.printStackTrace();
            return (char) -1; 
        }
    }
}
class Globals(){
    public static CharClass charClass;
    public static TokenCode nextToken;
    public static String lexeme;
    public static int token;
}

public class Sintactic {

    public static void main(String[] args) {
        
        ReadFile file = new ReadFile("program.in");
        Character currentChar;
        while( (currentChar = file.nextChar()) != (char)-1 ){
            System.out.println(currentChar);

        }


    }
    
}