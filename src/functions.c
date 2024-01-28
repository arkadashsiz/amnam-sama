#include "functions.h"

//compares two chars
int comp(char big, char small){
    if (big<small)
    {
        return 1;
    }
    else if (big==small)
    {
        return 0;
    }
    
    else{
        return -1;
    }
}
//compares two word with known length
int comp_word(char *A,char *B,int length){
    int res = 0;

    for (int i = 0; i < length; i++)
    {
        if(comp(*(A+i),*(B+i))==0){
            //
        }
        else if (comp(*(A+i),*(B+i))==1)
        {
            res=-1;
            break;
        }
        else{
            res = -1;
            break;
        }
        
    }
    
    return res;

}
//extracts int from string
int decipher(int length,char* string){
    int out_num=0;
    int pow =1;
    
    for (int i = length-2; i >=0; i--)
    {
        switch (*(string+i))
        {
        case '0':

            break;
        case '1':
            out_num+=pow;
            break;
        case '2':
            out_num+=pow*2;
            break;
        case '3':
            out_num+=pow*3;
            break;
        case '4':
            out_num+=pow*4;
            break;
        case '5':
            out_num+=pow*5;
            break;
        case '6':
            out_num+=pow*6;
            break;
        case '7':
            out_num+=pow*7;
            break;
        case '8':
            out_num+=pow*8;
            break;
        case '9':
            out_num+=pow*9;
            break;
        default:
            out_num=-1;
            break;
        
        }
        
        if (out_num==-1)
        {
            break;
        }
        
        pow*=10;
    }
    
    
    return out_num;
}
//extracts float from string(kinda)
float decipher_float(char *input,int length){
    float out_num=0;
    float pow=10;
    if (length==1)
    {
        pow=1;
    }
    
    if (*(input+1)=='.')
    {
        pow=1;
        
    }
    else if (*(input+2)=='.')
    {
        pow =10;
    }
    for (int i = 0; i < length; i++)
    {
        if (*(input+i)=='.')
        {
            continue;
        }
        
        switch (*(input+i))
        {
        case '0':

            break;
        case '1':
            out_num+=pow;
            break;
        case '2':
            out_num+=pow*2;
            break;
        case '3':
            out_num+=pow*3;
            break;
        case '4':
            out_num+=pow*4;
            break;
        case '5':
            out_num+=pow*5;
            break;
        case '6':
            out_num+=pow*6;
            break;
        case '7':
            out_num+=pow*7;
            break;
        case '8':
            out_num+=pow*8;
            break;
        case '9':
            out_num+=pow*9;
            break;
        default:
            out_num=-1;
            break;
        
        }
        pow/=10;
    }
    return out_num;

}
//size of a word with known start position
int word_size(char *A,int start_pos){
    int i=0;
    while (1)
    {
        
        if (*(A+i+start_pos)==' '||*(A+i+start_pos)=='\n'||*(A+i+start_pos)=='\0')
        {
            break;
        }
        
        i++;
    }
    return i;
}
//start position of a word knowing start position of another word
// and word distance between them
int word_pos(char *A,int start_pos,int amount){
    int ret_val=start_pos;
    for (int i = 0; i < amount; i++)
    {
        ret_val+=word_size(A,ret_val)+1;
    }
    return ret_val;

}
//takes a(string of all commands) and b(start position of each command in string a)
// and checks if string ((input)) is among them and returns the index
int switch_input(int size_of_string_a,char* input,char*a,int*b){
    int ret_val=-1;
    for (int i = 0; i < size_of_string_a-1; i++)
    {
        if (comp_word(input,(a+b[i]),word_size(a,b[i]))==0)
        {
            ret_val=i;
            break;
        }
        
    }
    return ret_val;

}
//copies string 1 to string 2
void copy(char* copy_to,char* copy_from,int length){
    for (int i = 0; i < length; i++)
    {
        *(copy_to+i)=*(copy_from+i);
    }
    


}
//empties a string(turns everything to ' ')
void empty_str(char* a,int length){

for (int i = 0; i < length; i++)
{
    *(a+i)=' ';
}

}
//number of words split by space,new line,endline
int num_words(char* a){
    int temp_val=0;
    int i=0;
    int was_space=0;
    while (1)
    {
        
        if (was_space==0&&(*(a+i)==' '||*(a+i)=='\0'||*(a+i)=='\n'))
        {
            temp_val++;
            was_space=1;
        }
        else if (*(a+i)!=' ')
        {
            was_space=0;
        }
        if (*(a+i)=='\0'||*(a+i)=='\n')
        {
            break;
        }
        i++;
    }
    return temp_val;
    
}

void copy_textfile(char* name ,FILE* file){
    char* data=(char*) calloc(10000,1);
    for (int i = 0; i < 10000; i++)
    {
        fscanf(file,"%c",(data+i));
    }
    int length = strlen(name);
    char o[5]=".txt";
    for (int i = length; i < length+4; i++)
    {
        *(name+i)=o[i-length];
    }
    *(name+length+4)='\0';
    FILE* a=fopen(name,"w+");
    for (int i = 0; i < 10000; i++)
    {
        fprintf(a,"%c",*(data+i));
    }
    fclose(a);
}

//above functions are reused from HW's

void read_command(FILE* command_file,int pos,char* word){
    int temp=pos;
    int temp2=temp;
    fseek(command_file,temp,0);
    int k=0;
    fscanf(command_file,"%c",(word+k));
    while (*(word+k)!='\n')
    {
        k++;
        temp++;
        fseek(command_file,temp,0);
        fscanf(command_file,"%c",(word+k));
    }
    *(word+k+1)='\0';
    fseek(command_file,temp2,0);
}

//returns the code for the given command
unsigned char command_detector(int argc,char *argv[],FILE* command_file,int number_commands){
    char command_code;
    for (int i = 1; i < argc; i++)
    {
        int arg_length=strlen(argv[i]);
        int pos=0;
        char* temp_word=(char*) calloc(100,1);
        for (int j = 0; j < number_commands; j++)
        {
            read_command(command_file,pos,temp_word);
            int word_leng=word_size(temp_word,0);
            if (arg_length!=word_leng)
            {
                /* code */
            }
            else if (comp_word(argv[i],temp_word,arg_length)==0)
            {
                /* code */
            }
            




            pos+=word_leng+1;
            
        }
        
    }
    




    return command_code;
}


int check_file(char* dir){
    
    FILE* file =fopen(dir,"r+");
    if (file==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }

}

int check_shiz_local_dir(char* file_dir){
    char h[6]="\\.shiz";
    int ww = strlen(file_dir);
    char* shiz_dir=(char*) calloc(256,1);
    strcpy(shiz_dir,file_dir);
    for (int i = 0; i < 6 ;i++)
    {
        *(shiz_dir+ww+i)=h[i];
    }
    // Check for file existence
    DIR* dir=opendir(shiz_dir);
    if (dir==NULL)
    {
        return 0;
    }
    closedir(dir);

    return 1;
  



}

int check_shiz_local_dir_rec(char* file_dir){
    char* dir=(char*) calloc(256,1);
    strcpy(dir,file_dir);
    char temp;
    for (int i = strlen(dir)-1; i >=0; i--)
    {
        temp=*(dir+i);
        if (temp=='\\')
        {
            *(dir+i)='\0';
            break;
        }
        else{
            *(dir+i)=' ';
        }
        
    }
    
    if (strcmp(dir,"C:")==0)
    {
        return 0;
    }
    
    int ret_val=check_shiz_local_dir(file_dir);
    if (ret_val==1)
    {
        return 1;
    }
    else{
        return check_shiz_local_dir_rec(dir);
    }

}


int config_glob_name(int argc,char *argv[]){
    int check =check_file("c:\\shiz\\name.txt");
    FILE* file;
    if (check==0)
    {
        file=fopen("c:\\shiz\\name.txt","r+");
    }
    else{
        file=fopen("c:\\shiz\\name.txt","w+");
    }
    
    fseek(file,0,0);
    fprintf(file,"username: %s \n",argv[4]);
    return 0;
}
int config_glob_email(int argc,char *argv[]){
    int check =check_file("c:\\shiz\\email.txt");
    FILE* file;
    if (check==0)
    {
        file=fopen("c:\\shiz\\email.txt","r+");
    }
    else{
        file=fopen("c:\\shiz\\email.txt","w+");
    }

    fseek(file,0,0);
    fprintf(file,"email: %s \n",argv[4]);
    return 0;
}

int check_global_dir(){
    DIR* dir=opendir("c:\\shiz");
    if (dir)
    {
        return 0;
    }
    else if (ENOENT ==errno)
    {
        DIR* shiz_dir =mkdir("c:\\shiz");
        return 1;
    }
    else{
        perror("failed to open dir for some unknown reason\n");
    }
    


}

void create_local_shiz_dir(char* e){
    
    int check =mkdir(e);
    if (check==0)
    {
        printf("directory created\n");
    }
    else{
        perror("failed to create directory\n");
    }
}

