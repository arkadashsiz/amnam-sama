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

void copy_textfile_withouttxt(char* name ,FILE* file){
    char* data=(char*) calloc(10000,1);
    for (int i = 0; i < 10000; i++)
    {
        fscanf(file,"%c",(data+i));
    }
    
    FILE* a=fopen(name,"w+");
    for (int i = 0; i < 10000; i++)
    {
        fprintf(a,"%c",*(data+i));
    }
    fclose(a);
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

int check_shiz_local_dir_rec(char* file_dir,int reverse_depth){
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
    
    if (strlen(dir)==2)
    {
        return -1;
    }
    
    int ret_val=check_shiz_local_dir(file_dir);
    if (ret_val==1)
    {
        return reverse_depth;
    }
    else{
        return check_shiz_local_dir_rec(dir,reverse_depth+1);
    }

}

int find_shiz_local_dir(char*output,char* file_dir,int depth){
    strcpy(output,file_dir);
    int size =strlen(output);
    if (depth==0)
    {
        *(output+size)='\0';
        return 0;
    }
    
    int counter=1;
    char temp;
    
    for (int i = size-1; i >=0; i--)
    {
        if (*(output+i)=='\\'&&counter<depth)
        {
            counter++;
            *(output+i)=' ';
        }
        else if (*(output+i)=='\\'&&counter==depth)
        {
            *(output+i)='\0';
            break;
        }
        else{
            *(output+i)=' ';
        }
        
    }
    return 0;

}

int check_is_real_command(char* command){
    //
    char* commands[100];
    for (int i = 0; i < 100; i++)
    {
        commands[i]=(char*) calloc(256,1);
    }
    strcpy(commands[0],"config -global user.name");
    strcpy(commands[1],"config -global user.email");
    strcpy(commands[2],"config user.email");
    strcpy(commands[3],"config user.name");
    strcpy(commands[4],"init");
    strcpy(commands[5],"add");
    strcpy(commands[6],"add -f");
    strcpy(commands[7],"add -n");
    strcpy(commands[8],"add -redo");
    strcpy(commands[9],"rest");
    strcpy(commands[10],"rest -undo");
    strcpy(commands[11],"status");
    strcpy(commands[12],"commit -m");
    strcpy(commands[13],"set -m");
    strcpy(commands[14],"replace -m");
    strcpy(commands[15],"remove -s");
    strcpy(commands[16],"log");
    strcpy(commands[17],"log -n");
    strcpy(commands[18],"log -branch");
    strcpy(commands[19],"log -author");
    strcpy(commands[20],"log -since");
    strcpy(commands[21],"log -before");
    strcpy(commands[22],"log -search");
    strcpy(commands[23],"branch");
    strcpy(commands[24],"checkout");
    strcpy(commands[25],"checkout HEAD");
    //
    int is_possible=0;
    for (int i = 0; i < 26; i++)
    {
        if (strcmp(command,commands[i])==0)
        {
            is_possible=1;
            break;
        }
        
    }
    
    return is_possible;


}

int config_glob_name(int argc,char *argv[]){
    int check =check_file("c:\\shiz\\name.txt");
    FILE* file;
    if (check==0)
    {
        file=fopen("c:\\shiz\\name.txt","w+");
    }
    else{
        file=fopen("c:\\shiz\\name.txt","w+");
    }
    
    fseek(file,0,0);
    fprintf(file,"name: %s \n",argv[4]);
    return 0;
}
int config_glob_email(int argc,char *argv[]){
    int check =check_file("c:\\shiz\\email.txt");
    FILE* file;
    if (check==0)
    {
        file=fopen("c:\\shiz\\email.txt","w+");
    }
    else{
        file=fopen("c:\\shiz\\email.txt","w+");
    }

    fseek(file,0,0);
    fprintf(file,"email: %s \n",argv[4]);
    return 0;
}
int config_glob_alias(int argc,char *argv[]){
    int check =check_file("c:\\shiz\\alias.txt");
    FILE* file;
    if (check==0)
    {
        file=fopen("c:\\shiz\\alias.txt","w+");
    }
    else{
        file=fopen("c:\\shiz\\alias.txt","w+");
    }
    fseek(file,0,0);
    char* alias=(char*) calloc(256,1);
    int reached_dot=0;
    int counter=0;
    for (int i = 0; i < strlen(argv[3]); i++)
    {
        if(*(argv[3]+i)=='.'){
            reached_dot=1;
        }
        else if (reached_dot==1)
        {
            *(alias+counter)=*(argv[3]+i);
            counter++;
        }
        
    }
    
    int flag1=check_is_real_command(argv[4]);
    if (flag1==1)
    {
        fprintf(file,"%s:%s \n",alias,argv[4]);
    }
    else{
        printf("Invalid Command\n");
    }
    
}


int config_email(int argc,char *argv[],char* current_dir){
    char* shiz_dir=(char*) calloc(256,1);
    find_shiz_local_dir(shiz_dir,current_dir,check_shiz_local_dir_rec(current_dir,0));
    int leng=strlen(shiz_dir);
    char shiz[7]="\\.shiz";
    for (int i = 0; i < 7; i++)
    {
        *(shiz_dir+leng+i)=shiz[i];
    }
    chdir(shiz_dir);
    //////
    FILE* file=fopen("email.txt","r+");
    if (file==NULL)
    {
        file=fopen("email.txt","w+");
    }
    fseek(file,0,0);
    fprintf(file,"email: %s \n",argv[argc-1]);
    return 0;
}
int config_name(int argc,char *argv[],char* current_dir){
    char* shiz_dir=(char*) calloc(256,1);
    find_shiz_local_dir(shiz_dir,current_dir,check_shiz_local_dir_rec(current_dir,0));
    int leng=strlen(shiz_dir);
    char shiz[7]="\\.shiz";
    for (int i = 0; i < 7; i++)
    {
        *(shiz_dir+leng+i)=shiz[i];
    }
    chdir(shiz_dir);
    /////
    FILE* file=fopen("name.txt","r+");
    if (file==NULL)
    {
        file=fopen("name.txt","w+");
    }
    fseek(file,0,0);
    fprintf(file,"name: %s \n",argv[argc-1]);
    return 0;
}
int config_alias(int argc,char *argv[],char* current_dir){
    char* shiz_dir=(char*) calloc(256,1);
    find_shiz_local_dir(shiz_dir,current_dir,check_shiz_local_dir_rec(current_dir,0));
    int leng=strlen(shiz_dir);
    char shiz[7]="\\.shiz";
    for (int i = 0; i < 7; i++)
    {
        *(shiz_dir+leng+i)=shiz[i];
    }
    chdir(shiz_dir);
    /////
    FILE* file=fopen("alias.txt","r+");
    if (file==NULL)
    {
        file=fopen("alias.txt","w+");
    }
    fseek(file,0,0);
    char* alias=(char*) calloc(256,1);
    int reached_dot=0;
    int counter=0;
    for (int i = 0; i < strlen(argv[2]); i++)
    {
        if(*(argv[2]+i)=='.'){
            reached_dot=1;
        }
        else if (reached_dot==1)
        {
            *(alias+counter)=*(argv[2]+i);
            counter++;
        }
        
    }
    
    int flag1=check_is_real_command(argv[3]);
    if (flag1==1)
    {
        fprintf(file,"%s:%s \n",alias,argv[3]);
    }
    else{
        printf("Invalid Command\n");
    }
    
}


int check_global_dir(){
    DIR* dir=opendir("c:\\shiz");
    if (dir)
    {
        return 0;
    }
    else if (ENOENT ==errno)
    {
        int shiz_dir =mkdir("c:\\shiz");
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

int comp_file(FILE* file1,FILE* file2){
    char a;
    char b;
    int ret_val=0;
    for (int i = 0; i < 10000; i++)
    {
        fseek(file1,i,0);
        fseek(file2,i,0);
        fscanf(file1,"%c",&a);
        fscanf(file2,"%c",&b);
        if (a!=b)
        {
            ret_val=i;
            break;
        }
        
        
    }
    
    return ret_val;

}

void hash_file(FILE* file,char* out){
    char md5_digest[MD5_DIGEST_LENGTH];
    char* data=( char*) calloc(10000,1);
    for (int i = 0; i < 10000; i++)
    {
        fseek(file,i,0);
        fscanf(file,"%c",data+i);
    }
    MD5(data,10000,md5_digest);
    char* cum_shit_piss=(char*) calloc(4000,1);
    for (int i = 0; i < 16; i++)
    {
        sprintf(cum_shit_piss+i,"%x",md5_digest[i]);
    }
    for (int i = 0; i < 16; i++)
    {
        *(out+i)=*(cum_shit_piss+i);    
    }

}


int send_file_to_stage(char* current_dir,char* file_loc){
    FILE* transfer_file=fopen(file_loc,"r+");
    char* file_stage_dir=(char*) calloc(256,1);
    find_shiz_local_dir(file_stage_dir,current_dir,check_shiz_local_dir_rec(current_dir,0));
    //adding ((/.shiz/stage)) to end of string

    append_str_to_str(file_stage_dir,file_stage_dir,"\\.shiz\\stage\\");
    //
    char* hash_code=(char*) calloc(16,1);
    hash_file(transfer_file,hash_code);
    char* just_file_name=(char*) calloc(256,1);
    int y=0;
    for (int i = strlen(file_loc); i >=0; i--)
    {
        if (*(file_loc)=='\\')
        {
            y=i;
            break;
        }
        
    }
    int counter=0;
    for (int i = y; i < strlen(file_loc); i++)
    {
        *(just_file_name+counter)=*(file_loc+i);
        counter++;
    }
    

    strcat(file_stage_dir,just_file_name);
    FILE* hash_file_stage=fopen(file_stage_dir,"w+");
    fprintf(hash_file_stage,"%s",hash_code);
    if (hash_file_stage==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
    
    
    

}

void append_str_to_str(char* str3,char*str1,char str2[]){
    
    
    //adding ((/.shiz/stage)) to end of string
    strcpy(str3,str1);
    int leng=strlen(str3);
    int leng2=strlen(str2);
    for (int i = 0; i < leng2; i++)
    {
        *(str3+leng+i)=str2[i];
    }
    *(str3+leng+leng2)='\0';
    //

}

int all_file_dirs(char* current_loc,char* file_dir_list[]){
    struct dirent *files;

    DIR *dir = opendir(current_loc);
    if (dir == NULL){
       printf("Directory cannot be opened!" );
    }
    int counter=-2;
    while ((files = readdir(dir)) != NULL){
        if (counter>=0)
        {
            strcpy(file_dir_list[counter],files->d_name);
        }
        
        
        counter++;
    }
        
    closedir(dir);
    return counter;
}


void listFilesRecursively(char *current_dir,char* out_list)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(current_dir);

    // Unable to open directory stream
    if (!dir)
    {
        return;
    }
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            strcat(out_list,current_dir);
            strcat(out_list,"\\");
            strcat(out_list,dp->d_name);
            strcat(out_list,"\n");
            
            // Construct new path from our base path
            strcpy(path, current_dir);
            strcat(path, "\\");
            strcat(path, dp->d_name);

            listFilesRecursively(path,out_list);
        }
    }

    closedir(dir);
}

int copy_file(char* copy_to_dir,char* file_dir){
    FILE* file=fopen(file_dir,"r+");
    char* copy_to_file=(char*) calloc(256,1);
    strcpy(copy_to_file,copy_to_dir);
    strcat(copy_to_file,"\\");
    char* file_name=(char*) calloc(256,1);
    int e;
    for (int i = 0; i < 35; i++)
    {
        if (*(file_dir+i)=='\\')
        {
            e=i;
        }
    }
    e++;
    strcpy(file_name,file_dir+e);
    printf("%s\n",file_name);
    strcat(copy_to_file,file_name);
    printf("%s\n",copy_to_file);
    copy_textfile(copy_to_file,file);




    return 0;
}


void turn_str_to_list(char* string,char* list[]){
    int pos=0;
    int leng;
    int i=0;
    do
    {
        leng=word_size(string,pos);
        copy(list[i],string+pos,leng);
        i++;
        pos=word_pos(string,pos,1);
    } while (leng>0);
}


int send_rec_to_stage(int size_of_shiz_dir,int size_of_cuurent_dir_string,char* current_dir,char* stage_dir){
    ////////////////////////////////
    DIR* test =opendir(current_dir);
    if (test==NULL)
    {
        printf("the folder named: %s does not exist\n",current_dir);
        return 0;
    }
    closedir(test);
    ////////////////////////////////////
    char* y=(char*) calloc(100000,1);
    
    listFilesRecursively(current_dir,y);
    char* list[100];
    for (int i = 0; i < 100; i++)
    {
        list[i]=(char*) calloc(256,1);
    }
    turn_str_to_list(y,list);
    
    ///////////////////////////////////////
    int count=0;
    while (strcmp(list[count],"")!=0)
    {
        count++;
    }
    //making higher folders in stage
    char* making_folders=(char*) calloc(256,1);
    strcpy(making_folders,current_dir+size_of_shiz_dir);
    int counter=0;
    
    char* temp_folder=(char*) calloc(256,1);
    strcpy(temp_folder,stage_dir);
    int stage_dir_len=strlen(temp_folder);
    for (int i = 0; i <= size_of_cuurent_dir_string-size_of_shiz_dir; i++)
    {
        if (*(making_folders+i)=='\\')
        {
            DIR* dor=opendir(temp_folder);
            if (dor==NULL)
            {
                mkdir(temp_folder);
            }
            closedir(dor);
            
            
        }
        *(temp_folder+stage_dir_len+i)=*(making_folders+i);

        
        
    }
    DIR* dor=opendir(temp_folder);
    if (dor==NULL)
    {
        mkdir(temp_folder);
    }
    closedir(dor);
    /////////////////////////////////////////////
    char* shiz=(char*) calloc(256,1);
    copy(shiz,current_dir,size_of_shiz_dir);
    strcat(shiz,"\\.shiz");
    
    ////////////////////////////////////////
    for (int i = 0; i < count; i++)
    {
        if (comp_word(shiz,list[i],strlen(shiz))==0)
        {
            /* code */
        }
        else{

        
        
        
            char* temp=(char*) calloc(256,1);
            strcpy(temp,list[i]+size_of_shiz_dir);
            char* new_loc=(char*) calloc(256,1);
            strcpy(new_loc,stage_dir);
            strcat(new_loc,temp);
            int leng =strlen(new_loc);
            int is_file=0;
            int wwwwwwwwwwwwwwwwwwww=0;
            for (int j = leng-1; j  >=0; j--)
            {
                if (wwwwwwwwwwwwwwwwwwww==1&&*(new_loc+j)=='\\')
                {
                    break;
                }
                else if (wwwwwwwwwwwwwwwwwwww==1&&*(new_loc+j)!='\\')
                {
                    is_file=1;
                }
                
                if (*(new_loc+j)=='.')
                {
                    wwwwwwwwwwwwwwwwwwww=1;
                    
                }

            }

            if (is_file)
            {
                FILE* file=fopen(list[i],"r+");
                FILE* does_exist=fopen(new_loc,"r");
                printf("%s\n",new_loc);
                if (does_exist==NULL)
                {
                    printf("didnt exist made it\n\n");
                    copy_textfile_withouttxt(new_loc,file);
                }
                else{

                    unsigned char* hash1=(unsigned char*) calloc(16,1);
                    unsigned char* hash2=(unsigned char*) calloc(16,1);
                    hash_file(file,hash1);
                    hash_file(does_exist,hash2);
                    if (comp_word(hash1,hash2,16)==0)
                    {
                        printf("the file .%s is alredy in stage\n",temp);
                    }
                    else{
                        printf("changes_comited\n\n");
                        copy_textfile_withouttxt(new_loc,file);
                    }

                }
                fclose(file);
                fclose(does_exist);
            }
            else{
                
                if (1)
                {
                    DIR* flag=opendir(new_loc);
                    if (flag==NULL)
                    {
                        mkdir(new_loc);
                    }
                    closedir(flag);
                }
                
                
            }
        
        }
        
        
        
    }
    return 0;
}

int send_to_storage(int size_of_shiz_dir,int size_of_cuurent_dir_string,char* file_or_dir,char* stage_dir,char* current_dir){
    //is file or not
    int siz=strlen(file_or_dir);
    int qqqqq=0;
    int is_file=0;
    for (int i = siz-1; i >=0; i--)
    {
        if (qqqqq==1&&*(file_or_dir+i)=='\\')
        {
            is_file=0;
            break;
        }
        else if (qqqqq==1&&*(file_or_dir+i)!='\\')
        {
            is_file=1;
            break;
        }
        
        
        if (*(file_or_dir+i)=='.')
        {
            qqqqq=1;
            
        }
        
    }
    /////////////////////////////////
    //if the given string isn't absloute it will make it absloute
    char* new_file_or_dir=(char*) calloc(256,1);
    if (*(file_or_dir+1)!=':')
    {
        strcpy(new_file_or_dir,current_dir);
        strcat(new_file_or_dir,"\\");
        strcat(new_file_or_dir,file_or_dir);
    }
    else{
        strcpy(new_file_or_dir,file_or_dir);
    }
    ///////////////////////////////////////////////////
    //making higher folders in stage
    char* making_folders=(char*) calloc(256,1);
    strcpy(making_folders,new_file_or_dir+size_of_shiz_dir);
    int counter=0;
    char* temp_folder=(char*) calloc(256,1);
    strcpy(temp_folder,stage_dir);
    int stage_dir_len=strlen(temp_folder);
    for (int i = 0; i <= size_of_cuurent_dir_string-size_of_shiz_dir; i++)
    {
        if (*(making_folders+i)=='\\')
        {
            DIR* dor=opendir(temp_folder);
            if (dor==NULL)
            {
                mkdir(temp_folder);
            }
            closedir(dor);
            
            
        }
        *(temp_folder+stage_dir_len+i)=*(making_folders+i);

        
        
    }
    DIR* dor=opendir(temp_folder);
    
    if (dor==NULL)
    {
        mkdir(temp_folder);
        
    }
    closedir(dor);
    ////////////////////////////////////
    //
    if (is_file)
    {
        char* temp=(char*) calloc(256,1);
        strcpy(temp,new_file_or_dir+size_of_shiz_dir);
        char* new_loc=(char*) calloc(256,1);
        strcpy(new_loc,stage_dir);
        strcat(new_loc,temp);
        FILE* file=fopen(file_or_dir,"r+");
        if (file==NULL)
        {
            printf("the file named: %s does not exist\n",file_or_dir);
            return 0;
        }
        
        FILE* does_exist=fopen(new_loc,"r+");
        if (does_exist==NULL)
        {

            copy_textfile_withouttxt(new_loc,file);
            printf("sent to storage\n");
        }
        else{
            unsigned char* hash1=(unsigned char*) calloc(16,1);
            unsigned char* hash2=(unsigned char*) calloc(16,1);
            hash_file(file,hash1);
            hash_file(does_exist,hash2);
            if (comp_word(hash1,hash2,16)==0)
            {
                printf("the file .%s is alredy in stage\n",temp);
            }
            else{
                printf("changes_comited\n\n");
                copy_textfile_withouttxt(new_loc,file);
            }
        }
    }
    else{
        printf("isten");
        send_rec_to_stage(size_of_shiz_dir,strlen(new_file_or_dir),new_file_or_dir,stage_dir);
    }
}


int check_if_staged(char* file_or_dir,char* stage_dir,char* shiz_dir){
    char* test_current_dir=(char*) calloc(256,1);
    char* test_stage_dir=(char*) calloc(256,1);
    strcpy(test_current_dir,file_or_dir+strlen(shiz_dir));
    strcpy(test_stage_dir,stage_dir);
    strcat(test_stage_dir,test_current_dir);
    DIR* dr=opendir(test_stage_dir);
    if (dr==NULL)
    {
    }
    else{
        return 0;
    }
    
    FILE* file=fopen(test_stage_dir,"r+");
    FILE* orig_file=fopen(file_or_dir,"r+");
    if (file==NULL)
    {
        return -1;
    }
    else{
        char* hash1=(char*) calloc(16,1);
        char* hash2=(char*) calloc(16,1);
        hash_file(file,hash1);
        hash_file(orig_file,hash2);
        if (strcmp(hash1,hash2)==0)
        {
            return 1;
        }
        else{
            return 2;
        }
        
    }
    
}

void listFilesRecursively_with_depth(char *current_dir,char* out_list,int depth){
    if (depth==0)
    {
        return;
    }
    
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(current_dir);

    // Unable to open directory stream
    if (!dir)
    {
        return;
    }
        
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            strcat(out_list,current_dir);
            strcat(out_list,"\\");
            strcat(out_list,dp->d_name);
            strcat(out_list,"\n");
            
            // Construct new path from our base path
            strcpy(path, current_dir);
            strcat(path, "\\");
            strcat(path, dp->d_name);

            listFilesRecursively_with_depth(path,out_list,depth-1);
        }
    }

    closedir(dir);
}

void check_staged_rec(char* current_dir,char* stage_dir,char* shiz_dir,int depth){
    
    
    char* temp=(char*) calloc(10000,1);
    if (depth==0)
    {
        listFilesRecursively(current_dir,temp);
    }
    else{
        listFilesRecursively_with_depth(current_dir,temp,depth);
    }
    char* list_file[100];
    for (int i = 0; i < 100; i++)
    {
        list_file[i]=(char*) calloc(256,1);

    }
    turn_str_to_list(temp,list_file);
    ///////////////////////////////
    int count=0;
    while (strcmp(list_file[count],"")!=0)
    {
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%s is %d\n",list_file[i],check_if_staged(list_file[i],stage_dir,shiz_dir));
    }
    

}


void redo_stage(char* stage_dir,char* shiz_dir){
    char* temp =(char*) calloc(10000,1);
    listFilesRecursively_stage(stage_dir,temp);
    char* list_files_stage[100];
    for (int i = 0; i < 100; i++)
    {
        list_files_stage[i]=(char*) calloc(256,1);
    }
    turn_str_to_list(temp,list_files_stage);
    int count=0;
    while (strcmp(list_files_stage[count],"")!=0)
    {
        count++;
    }
    /////////////////////////////////////
    char* temp2 =(char*) calloc(10000,1);
    listFilesRecursively(shiz_dir,temp2);
    char* list_files[100];
    for (int i = 0; i < 100; i++)
    {
        list_files[i]=(char*) calloc(256,1);
    }
    turn_str_to_list(temp2,list_files);
    int count1=0;
    while (strcmp(list_files[count1],"")!=0)
    {
        count1++;
    }
    /////////////////////////////////////
    int does_exist=0;
    for (int j = 0; j < count1; j++)
        {
            does_exist=0;
            for (int k = 0; k < count; k++)
            {
                if (strcmp(list_files_stage[k]+strlen(stage_dir),list_files[j]+strlen(shiz_dir))==0)
                {
                    does_exist=1;
                    break;
                }
            }
            if (does_exist==0&&*(list_files[j]+strlen(shiz_dir)+1)!='.')
            {
                printf("%s: -A\n",list_files[j]);
            }
            
            
            
        }
    for (int i = 0; i < count; i++)
    {
        int x=check_if_staged_reverse(list_files_stage[i],stage_dir,shiz_dir);
        
        char* out1=(char*) calloc(256,1);
        strcpy(out1,shiz_dir);
        strcat(out1,list_files_stage[i]+strlen(stage_dir));
        if (comp_word(list_files[i],shiz_dir,strlen(shiz_dir))==0)
        {
            if (x==0)
            {
                
            }
            else if (x==1)
            {
                
            }
            else if (x==2)
            {
                send_to_storage(strlen(shiz_dir),strlen(shiz_dir),list_files[i],stage_dir,shiz_dir);
            }
            else if (x==-1)
            {
                
            }
        }
        
        
        
    }





















}

void unstage(char* stage_dir,char* shiz_dir,char* file_or_dir,char* current_dir){
    int siz=strlen(file_or_dir);
    int qqqqq=0;
    int is_file=0;
    for (int i = siz-1; i >=0; i--)
    {
        if (qqqqq==1&&*(file_or_dir+i)=='\\')
        {
            is_file=0;
            break;
        }
        else if (qqqqq==1&&*(file_or_dir+i)!='\\')
        {
            is_file=1;
            break;
        }
        
        
        if (*(file_or_dir+i)=='.')
        {
            qqqqq=1;
            
        }
        
    }
    char* new_file_or_dir=(char*) calloc(256,1);
    if (*(file_or_dir+1)!=':')
    {
        strcpy(new_file_or_dir,current_dir);
        strcat(new_file_or_dir,"\\");
        strcat(new_file_or_dir,file_or_dir);
    }
    else{
        strcpy(new_file_or_dir,file_or_dir);
    }
    char* test_current_dir=(char*) calloc(256,1);
    char* test_stage_dir=(char*) calloc(256,1);
    strcpy(test_current_dir,new_file_or_dir+strlen(shiz_dir));
    strcpy(test_stage_dir,stage_dir);
    strcat(test_stage_dir,test_current_dir);
    DIR* dr=opendir(test_stage_dir);
    int x;
    if (dr==NULL)
    {

    }
    else{
        closedir(dr);
        x=remove(test_stage_dir);
        if (x==0)
        {
            printf("%s removed from stage\n",file_or_dir);
        }
        else{
            printf("directory not deleted\n");
        }
    }
    
    FILE* file=fopen(test_stage_dir,"r+");
    if (file==NULL)
    {
        
    }
    else{
        fclose(file);
        x=remove(test_stage_dir);
        if (x==0)
        {
            printf("%s removed from stage\n",file_or_dir);
        }
        else{
            printf("file not deleted\n");
        }
        
    }
}

void undo(char* stage_dir,char* shiz_dir){
    //to be implemented
}

int check_if_staged_reverse(char* file_or_dir,char* stage_dir,char* shiz_dir){
    char* test_current_dir=(char*) calloc(256,1);
    char* test_stage_dir=(char*) calloc(256,1);
    strcpy(test_stage_dir,file_or_dir+strlen(stage_dir));
    strcpy(test_current_dir,shiz_dir);
    strcat(test_current_dir,test_stage_dir);
    DIR* dr=opendir(test_current_dir);
    if (dr==NULL)
    {
    }
    else{
        return 0;
    }
    
    FILE* file=fopen(test_current_dir,"r+");
    FILE* orig_file=fopen(file_or_dir,"r+");
    if (file==NULL)
    {
        return -1;
    }
    else{
        char* hash1=(char*) calloc(16,1);
        char* hash2=(char*) calloc(16,1);
        hash_file(file,hash1);
        hash_file(orig_file,hash2);
        if (strcmp(hash1,hash2)==0)
        {
            return 1;
        }
        else{
            return 2;
        }
        
    }
}


void listFilesRecursively_stage(char *stage_dir,char* out_list){
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(stage_dir);

    // Unable to open directory stream
    if (!dir)
    {
        return;
    }
        
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            strcat(out_list,stage_dir);
            strcat(out_list,"\\");
            strcat(out_list,dp->d_name);
            strcat(out_list,"\n");
            
            // Construct new path from our base path
            strcpy(path, stage_dir);
            strcat(path, "\\");
            strcat(path, dp->d_name);

            listFilesRecursively(path,out_list);
        }
    }

    closedir(dir);
}


void status(char* current_dir,char* stage_dir,char* shiz_dir){
    char* temp =(char*) calloc(10000,1);
    listFilesRecursively_stage(stage_dir,temp);
    char* list_files_stage[100];
    for (int i = 0; i < 100; i++)
    {
        list_files_stage[i]=(char*) calloc(256,1);
    }
    turn_str_to_list(temp,list_files_stage);
    int count=0;
    while (strcmp(list_files_stage[count],"")!=0)
    {
        count++;
    }
    /////////////////////////////////////
    char* temp2 =(char*) calloc(10000,1);
    listFilesRecursively(current_dir,temp2);
    char* list_files[100];
    for (int i = 0; i < 100; i++)
    {
        list_files[i]=(char*) calloc(256,1);
    }
    turn_str_to_list(temp2,list_files);
    int count1=0;
    while (strcmp(list_files[count1],"")!=0)
    {
        count1++;
    }
    /////////////////////////////////////
    int does_exist=0;
    for (int j = 0; j < count1; j++)
        {
            does_exist=0;
            for (int k = 0; k < count; k++)
            {
                if (strcmp(list_files_stage[k]+strlen(stage_dir),list_files[j]+strlen(shiz_dir))==0)
                {
                    does_exist=1;
                    break;
                }
            }
            if (does_exist==0&&*(list_files[j]+strlen(shiz_dir)+1)!='.')
            {
                printf("%s: -A\n",list_files[j]);
            }
            
            
            
        }
    for (int i = 0; i < count; i++)
    {
        int x=check_if_staged_reverse(list_files_stage[i],stage_dir,shiz_dir);
        
        char* out1=(char*) calloc(256,1);
        strcpy(out1,shiz_dir);
        strcat(out1,list_files_stage[i]+strlen(stage_dir));
        if (comp_word(list_files[i],current_dir,strlen(current_dir))==0)
        {
            if (x==0)
            {
                printf("%s: folder\n",out1);
            }
            else if (x==1)
            {
                printf("%s: unmodified\n",out1);
            }
            else if (x==2)
            {
                printf("%s: +M\n",out1);
            }
            else if (x==-1)
            {
                printf("%s: +D\n",out1);
            }
        }
        
        
        
    }
    

}

int number_files(char* stage_dir){
    char* ws=(char*) calloc(10000,1);
    char* awoga[100];
    for (int i = 0; i < 100; i++)
    {
        awoga[i]=(char*) calloc(256,1);
    }
    listFilesRecursively(stage_dir,ws);
    turn_str_to_list(ws,awoga);
    int count=0;
    while (strcmp(awoga[count],"")!=0)
    {
        count++;
    }
    return count;
}

void empty_dir(char* dir){
    char* temp=(char*) calloc(10000,1);
    char* files[100];
    for (int i = 0; i < 100; i++)
    {
        files[i]=(char*) calloc(256,1);
    }
    listFilesRecursively(dir,temp);
    turn_str_to_list(temp,files);
    int count=0;
    while (strcmp(files[count],"")!=0)
    {
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        int siz=strlen(files[i]);
        int qqqqq=0;
        int is_file=0;
        for (int j = siz-1; j >=0; j--)
        {
            if (qqqqq==1&&*(files[i]+j)=='\\')
            {
                is_file=0;
                break;
            }
            else if (qqqqq==1&&*(files[i]+j)!='\\')
            {
                is_file=1;
                break;
            }


            if (*(files[i]+j)=='.')
            {
                qqqqq=1;

            }

        }
        if (is_file==1)
        {
            
            remove(files[i]);
        }
        
    
    }
    for (int i = 0; i < count; i++)
    {
        int siz=strlen(files[i]);
        int qqqqq=0;
        int is_file=0;
        for (int j = siz-1; j >=0; j--)
        {
            if (qqqqq==1&&*(files[i]+j)=='\\')
            {
                is_file=0;
                break;
            }
            else if (qqqqq==1&&*(files[i]+j)!='\\')
            {
                is_file=1;
                break;
            }


            if (*(files[i]+j)=='.')
            {
                qqqqq=1;

            }

        }
        if (is_file==0)
        {
            
            _rmdir(files[i]);
        }
        
    
    }

    
}





void listFilesRecursively_noshiz(char* shiz_dir,char *current_dir,char* out_list)
{
    char* temp=(char*) calloc(256,1);
    strcpy(temp,shiz_dir);
    strcat(temp,"\\.shiz");
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(current_dir);

    // Unable to open directory stream
    if (!dir)
    {
        return;
    }
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            strcat(out_list,current_dir);
            strcat(out_list,"\\");
            strcat(out_list,dp->d_name);
            strcat(out_list,"\n");
            
            // Construct new path from our base path
            strcpy(path, current_dir);
            strcat(path, "\\");
            strcat(path, dp->d_name);
            if (comp_word(path,temp,strlen(temp))==0)
            {
                /* code */
            }
            else{
                listFilesRecursively_noshiz(shiz_dir,path,out_list);
            }
            
        }
    }

    closedir(dir);
}




void empty_shiz_dir(char* shiz_dir){
    char* temp=(char*) calloc(10000,1);
    char* files[100];
    for (int i = 0; i < 100; i++)
    {
        files[i]=(char*) calloc(256,1);
    }
    listFilesRecursively_noshiz(shiz_dir,shiz_dir,temp);
    turn_str_to_list(temp,files);
    int count=0;

    while (strcmp(files[count],"")!=0)
    {
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        int siz=strlen(files[i]);
        int qqqqq=0;
        int is_file=0;
        for (int j = siz-1; j >=0; j--)
        {
            if (qqqqq==1&&*(files[i]+j)=='\\')
            {
                is_file=0;
                break;
            }
            else if (qqqqq==1&&*(files[i]+j)!='\\')
            {
                is_file=1;
                break;
            }


            if (*(files[i]+j)=='.')
            {
                qqqqq=1;

            }

        }
        if (is_file==1)
        {
            
            remove(files[i]);
        }
        
    
    }
    for (int i = 0; i < count; i++)
    {
        int siz=strlen(files[i]);
        int qqqqq=0;
        int is_file=0;
        for (int j = siz-1; j >=0; j--)
        {
            if (qqqqq==1&&*(files[i]+j)=='\\')
            {
                is_file=0;
                break;
            }
            else if (qqqqq==1&&*(files[i]+j)!='\\')
            {
                is_file=1;
                break;
            }


            if (*(files[i]+j)=='.')
            {
                qqqqq=1;

            }

        }
        if (is_file==0)
        {
            
            _rmdir(files[i]);
        }
        
    
    }



}

void commit(char* previous_branch,int number_files,char* user_name,char* current_branch,char* commit_message,char* stage_dir,char* storage_dir,char* shiz_dir){
    
    if (strlen(commit_message)>72)
    {
        printf("coomit message should be smaller than 72 charecters\n");
        return;
    }
    else if (commit_message==NULL)
    {
        printf("no commit message\n");
        return;
    }
    else if (number_files==0)
    {
        printf("there is no files in stage\n");
        return;
    }
    
    ///////////////////////
    time_t t = time(NULL);
    struct tm time = *localtime(&t);
    char* hash_id=( char*) calloc(16,1);
    char* commit_dir=(char*) calloc(256,1);
    strcpy(commit_dir,storage_dir);
    strcat(commit_dir,"\\");
    strcat(commit_dir,current_branch);
    mkdir(commit_dir);
    send_rec_to_stage(strlen(stage_dir),strlen(stage_dir),stage_dir,commit_dir);


    strcat(commit_dir,".txt");
    FILE* data_file=fopen(commit_dir,"w+");
    fprintf(data_file,"%s\n",previous_branch);
    strcpy(previous_branch,current_branch);
    


    ;
    fseek(data_file,0,2);
    fprintf(data_file,"%d-%02d-%02d %02d:%02d:%02d\n", time.tm_year + 1900, time.tm_mon + 1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    fseek(data_file,0,2);
    fprintf(data_file,"%s\n",commit_message);
    fseek(data_file,0,2);
    fprintf(data_file,"%s\n",user_name);
    hash_file(data_file,hash_id);
    fseek(data_file,0,2);
    fprintf(data_file,"%s\n",hash_id);
    fseek(data_file,0,2);
    fprintf(data_file,"%d\n",number_files);
    
    fclose(data_file);
    //changing current branch
    int x= strlen(current_branch);
    int y;
    for (int i = x-1; i >=0; i--)
    {
        if (*(current_branch+i)=='_')
        {
            y=i;
            break;
        }
        
    }
    int next_num=decipher(x-y,current_branch+y+1);
    next_num++;
    sprintf(current_branch+y+1,"%d",next_num);
    char* open_loc_head=(char*) calloc(256,1);
    strcpy(open_loc_head,storage_dir);
    strcat(open_loc_head,"\\head_branch.txt");
    FILE* init_loove=fopen(open_loc_head,"r+");
    fprintf(init_loove,"%s",current_branch);
    





    
    
}


void show_commit_id(char* commit_id){




}



void branch(char* branch_name,char* current_branch,char* previous_branch,char* storage_dir){
    char* new_name=(char*) calloc(256,1);
    strcpy(new_name,branch_name);
    strcat(new_name,"_0");
    strcpy(current_branch,new_name);
    char* current_branch_file=(char*) calloc(256,1);
    strcpy(current_branch_file,storage_dir);
    strcat(current_branch_file,"\\current_branch.txt");
    FILE* file=fopen(current_branch_file,"w+");
    fprintf(file,"%s",new_name);    
    empty_str(current_branch_file,256);
    strcpy(current_branch_file,storage_dir);
    strcat(current_branch_file,"\\all_branch.txt");
    fclose(file);
    file=fopen(current_branch_file,"r+");
    fseek(file,0,2);
    fprintf(file,"%s\n",branch_name);
    char* init_loc=(char*) calloc(256,1);
    strcpy(init_loc,storage_dir);
    strcat(init_loc,"\\head_branch.txt");
    FILE* init_loove=fopen(init_loc,"w+");
    fprintf(init_loove,"%s",new_name);
    fclose(init_loove);

}

void show_all_branches(char* storage_dir){
    char* loc=(char*) calloc(256,1);
    strcpy(loc,storage_dir);
    strcat(loc,"\\all_branch.txt");
    FILE* file=fopen(loc,"r+");
    char* data=(char*) calloc(1000,1);
    for (int i = 0; i < 1000; i++)
    {
        fscanf(file,"%c",data+i);
    }
    printf("%s",data);
    fclose(file);
}


int compare_two_dates(int* a,int* b){
    int ret_val=1;//a>b
    for (int i = 0; i < 6; i++)
    {
        if (*(a+i)>*(b+i))
        {
            continue;
        }
        else if (*(a+i)==*(b+i))
        {
            continue;
        }
        else if (*(a+i)<*(b+i))
        {
            ret_val=-1;
            break;
        }
        
        
        
    }
    
    return ret_val;

}

void sort_file_by_date(char* files[],int* nums[],int length_arrays){
    
    for (int i = 0; i < length_arrays; i++)
    {
        
        int swapped=0;
        for (int j = 0; j < length_arrays-i-1; j++)
        {
            int* temp2=(int*) calloc(4,6);
            char* temp=(char*) calloc(256,1);

            if (compare_two_dates(nums[j],nums[j+1])==-1)
            {
                swapped=1;
                for (int w = 0; w < 6; w++)
                {
                    *(temp2+w)=*(nums[j]+w);
                }
                for (int w = 0; w < 6; w++)
                {
                    *(nums[j]+w)=*(nums[j+1]+w);
                }
                for (int w = 0; w < 6; w++)
                {
                    *(nums[j+1]+w)=*(temp2+w);
                }
                strcpy(temp,files[j]);
                strcpy(files[j],files[j+1]);
                strcpy(files[j+1],temp);
            }
            
        }
        if (swapped==0)
        {
            break;
        }
        
        
    }
    

}


void logs(int how_many_you_want_you_cute_little_shit_i_hate_you,char* storage_dir){
    char* temp=(char*) calloc(10000,1);
    char* list[100];
    for (int i = 0; i < 100; i++)
    {
        list[i]=(char*) calloc(256,1);
    }
    listFilesRecursively_with_depth(storage_dir,temp,1);
    
    turn_str_to_list(temp,list);
    int count=0;
    while (strcmp(list[count],"")!=0)
    {
        count++;
    }
    
    ///////////////////////////////////////////
    char* all_branch=(char*) calloc(256,1);
    char* head_branch=(char*) calloc(256,1);
    char* current_branch=(char*) calloc(256,1);
    char* previous_branch=(char*) calloc(256,1);
    strcpy(previous_branch,storage_dir);
    strcpy(all_branch,storage_dir);
    strcpy(head_branch,storage_dir);
    strcpy(current_branch,storage_dir);
    strcat(previous_branch,"\\previous_branch.txt");
    strcat(all_branch,"\\all_branch.txt");
    strcat(head_branch,"\\head_branch.txt");
    strcat(current_branch,"\\current_branch.txt");
    char* names2[100];
    int* a[100];
    for (int i = 0; i < 100; i++)
    {
        a[i]=(int*) calloc(4,6);
    }
    
    for (int i = 0; i < 100; i++)
    {
        names2[i]=(char*) calloc(256,1);
    }
    int counter2=0;
    for (int i = 0; i < count; i++)
    {
        int siz=strlen(list[i]);
        int qqqqq=0;
        int is_file=0;
        for (int j = siz-1; j >=0; j--)
        {
            if (qqqqq==1&&*(list[i]+j)=='\\')
            {
                is_file=0;
                break;
            }
            else if (qqqqq==1&&*(list[i]+j)!='\\')
            {
                is_file=1;
                break;
            }


            if (*(list[i]+j)=='.')
            {
                qqqqq=1;

            }

        }
        if (is_file&&comp_word(list[i],all_branch,strlen(all_branch))!=0&&comp_word(list[i],head_branch,strlen(head_branch))!=0&&comp_word(list[i],current_branch,strlen(current_branch))!=0&&comp_word(list[i],previous_branch,strlen(previous_branch))!=0)
        {
            strcpy(names2[counter2],list[i]);
            counter2++;
        }
        
    }
    FILE* data_file;
    for (int i = 0; i < counter2; i++)
    {
       data_file=fopen(names2[i],"r+");
       
       
       char* MUDA=(char*) calloc(256,1);
       
       fscanf(data_file,"%s\n%d-%d-%d %d:%d:%d",MUDA,a[i]+0,a[i]+1,a[i]+2,a[i]+3,a[i]+4,a[i]+5);
       fclose(data_file);
       
    }
    
    sort_file_by_date(names2,a,counter2);
    if (how_many_you_want_you_cute_little_shit_i_hate_you<=0)
    {
        
        FILE* fo_fi_fa_fu;
        for (int i = 0; i < counter2; i++)
        {
            char* sick_loli_data=(char*) calloc(1000,1);
            fo_fi_fa_fu=fopen(names2[i],"r+");
            for (int j = 0; j < 1000; j++)
            {
                fscanf(fo_fi_fa_fu,"%c",sick_loli_data+j);
            }
            printf("DATA:\n%s\n",sick_loli_data);
            fclose(fo_fi_fa_fu);
            empty_str(sick_loli_data,1000);
        }
    }
    else{
        
        FILE* fo_fi_fa_fu;
        for (int i = 0; i < how_many_you_want_you_cute_little_shit_i_hate_you; i++)
        {
            char* sick_loli_data=(char*) calloc(1000,1);
            fo_fi_fa_fu=fopen(names2[i],"r+");
            for (int j = 0; j < 1000; j++)
            {
                fscanf(fo_fi_fa_fu,"%c",sick_loli_data+j);
            }
            printf("DATA:\n%s\n",sick_loli_data);
            fclose(fo_fi_fa_fu);
            empty_str(sick_loli_data,1000);
        }
    }
    
    
}


void logs_branch(char* branch_name,char* storage_dir){
    char* all_branch_loc=(char*) calloc(256,1);
    strcpy(all_branch_loc,storage_dir);
    strcat(all_branch_loc,"\\all_branch.txt");
    FILE* file=fopen(all_branch_loc,"r+");
    char* data=(char*) calloc(1000,1);
    for (int i = 0; i < 1000; i++)
    {
        fscanf(file,"%c",data+i);
    }
    fclose(file);
    char* branches[100];
    for (int i = 0; i < 100; i++)
    {
        branches[i]=(char*) calloc(256,1);
    }
    turn_str_to_list(data,branches);
    free(data);
    
    int count=0;
    while (strcmp(branches[count],"")!=0)
    {
        count++;
    }
    /////////////////////
    int posible=0;
    
    for (int i = 0; i < count; i++)
    {
        if (strcmp(branch_name,branches[i])==0)
        {
            posible=1;
            break;
        }
        
    }
    
    if (posible)
    {
        char* temp=(char*) calloc(10000,1);
        char* list[100];
        for (int i = 0; i < 100; i++)
        {
            list[i]=(char*) calloc(256,1);
        }
        listFilesRecursively_with_depth(storage_dir,temp,1);

        turn_str_to_list(temp,list);
        int count=0;
        while (strcmp(list[count],"")!=0)
        {
            count++;
        }

        ///////////////////////////////////////////
        char* all_branch=(char*) calloc(256,1);
        char* head_branch=(char*) calloc(256,1);
        char* current_branch=(char*) calloc(256,1);
        char* previous_branch=(char*) calloc(256,1);
        strcpy(previous_branch,storage_dir);
        strcpy(all_branch,storage_dir);
        strcpy(head_branch,storage_dir);
        strcpy(current_branch,storage_dir);
        strcat(previous_branch,"\\previous_branch.txt");
        strcat(all_branch,"\\all_branch.txt");
        strcat(head_branch,"\\head_branch.txt");
        strcat(current_branch,"\\current_branch.txt");
        char* names2[100];
        int* a[100];
        for (int i = 0; i < 100; i++)
        {
            a[i]=(int*) calloc(4,6);
        }

        for (int i = 0; i < 100; i++)
        {
            names2[i]=(char*) calloc(256,1);
        }
        int counter2=0;
        for (int i = 0; i < count; i++)
        {
            int siz=strlen(list[i]);
            int qqqqq=0;
            int is_file=0;
            for (int j = siz-1; j >=0; j--)
            {
                if (qqqqq==1&&*(list[i]+j)=='\\')
                {
                    is_file=0;
                    break;
                }
                else if (qqqqq==1&&*(list[i]+j)!='\\')
                {
                    is_file=1;
                    break;
                }


                if (*(list[i]+j)=='.')
                {
                    qqqqq=1;

                }

            }
            if (is_file&&comp_word(list[i],all_branch,strlen(all_branch))!=0&&comp_word(list[i],head_branch,strlen(head_branch))!=0&&comp_word(list[i],current_branch,strlen(current_branch))!=0&&comp_word(list[i],previous_branch,strlen(previous_branch))!=0)
            {
                strcpy(names2[counter2],list[i]);
                counter2++;
            }

        }
        FILE* data_file;
        for (int i = 0; i < counter2; i++)
        {
           data_file=fopen(names2[i],"r+");


           char* MUDA=(char*) calloc(256,1);

           fscanf(data_file,"%s\n%d-%d-%d %d:%d:%d",MUDA,a[i]+0,a[i]+1,a[i]+2,a[i]+3,a[i]+4,a[i]+5);
           fclose(data_file);

        }
        sort_file_by_date(names2,a,counter2);
    
        
        FILE* fo_fi_fa_fu;
        for (int i = 0; i < counter2; i++)
        {
            if (comp_word(names2[i]+strlen(storage_dir)+1,branch_name,strlen(branch_name))==0)
            {
                char* sick_loli_data=(char*) calloc(1000,1);
                fo_fi_fa_fu=fopen(names2[i],"r+");
                for (int j = 0; j < 1000; j++)
                {
                    fscanf(fo_fi_fa_fu,"%c",sick_loli_data+j);
                }
                printf("DATA:\n%s\n",sick_loli_data);
                printf("-------------------------\n");
                fclose(fo_fi_fa_fu);
                empty_str(sick_loli_data,1000);
            }
            
            
        }
    
    
    }
    else{
        printf("no such branch exists\n");
    }



}


void logs_author(char* author_name,char* storage_dir){
    char* temp=(char*) calloc(10000,1);
    char* list[100];
    for (int i = 0; i < 100; i++)
    {
        list[i]=(char*) calloc(256,1);
    }
    listFilesRecursively_with_depth(storage_dir,temp,1);
    
    turn_str_to_list(temp,list);
    int count=0;
    while (strcmp(list[count],"")!=0)
    {
        count++;
    }
    
    ///////////////////////////////////////////
    char* all_branch=(char*) calloc(256,1);
    char* head_branch=(char*) calloc(256,1);
    char* current_branch=(char*) calloc(256,1);
    char* previous_branch=(char*) calloc(256,1);
    strcpy(previous_branch,storage_dir);
    strcpy(all_branch,storage_dir);
    strcpy(head_branch,storage_dir);
    strcpy(current_branch,storage_dir);
    strcat(previous_branch,"\\previous_branch.txt");
    strcat(all_branch,"\\all_branch.txt");
    strcat(head_branch,"\\head_branch.txt");
    strcat(current_branch,"\\current_branch.txt");
    char* names2[100];
    char* authors[100];
    for (int i = 0; i < 100; i++)
    {
        authors[i]=(char*) calloc(256,1);
    }
    
    
    for (int i = 0; i < 100; i++)
    {
        names2[i]=(char*) calloc(256,1);
    }
    int* a[100];
    for (int i = 0; i < 100; i++)
    {
        a[i]=(int*) calloc(6,4);
    }
    
    int counter2=0;
    for (int i = 0; i < count; i++)
    {
        int siz=strlen(list[i]);
        int qqqqq=0;
        int is_file=0;
        for (int j = siz-1; j >=0; j--)
        {
            if (qqqqq==1&&*(list[i]+j)=='\\')
            {
                is_file=0;
                break;
            }
            else if (qqqqq==1&&*(list[i]+j)!='\\')
            {
                is_file=1;
                break;
            }


            if (*(list[i]+j)=='.')
            {
                qqqqq=1;

            }

        }
        if (is_file&&comp_word(list[i],all_branch,strlen(all_branch))!=0&&comp_word(list[i],head_branch,strlen(head_branch))!=0&&comp_word(list[i],current_branch,strlen(current_branch))!=0&&comp_word(list[i],previous_branch,strlen(previous_branch))!=0)
        {
            strcpy(names2[counter2],list[i]);
            counter2++;
        }
        
    }
    
    FILE* data_file;
    char* MUDA;
    for (int i = 0; i < counter2; i++)
    {
       data_file=fopen(names2[i],"r+");
       
       
       MUDA=(char*) calloc(256,1);
       fscanf(data_file,"%s\n%d-%d-%d %d:%d:%d\n%s\n%s\n",MUDA,a[i]+0,a[i]+1,a[i]+2,a[i]+3,a[i]+4,a[i]+5);
       fclose(data_file);
       
    }
    
    sort_file_by_date(names2,a,counter2);
    for (int i = 0; i < counter2; i++)
    {
       data_file=fopen(names2[i],"r+");
       
       
       MUDA=(char*) calloc(256,1);
       char* MUDA2=(char*) calloc(256,1);
       fscanf(data_file,"%s\n%d-%d-%d %d:%d:%d\n%s\n%s\n",MUDA,a[i]+0,a[i]+1,a[i]+2,a[i]+3,a[i]+4,a[i]+5,MUDA2,authors[i]);
       fclose(data_file);
       
    }
        
        FILE* fo_fi_fa_fu;
        for (int i = 0; i < counter2; i++)
        {
            fo_fi_fa_fu=fopen(names2[i],"r+");
            char* sick_loli_data=(char*) calloc(1000,1);
            if (strcmp(authors[i],author_name)==0)
            {
                for (int j = 0; j < 1000; j++)
                {
                    fscanf(fo_fi_fa_fu,"%c",sick_loli_data+j);
                }
                printf("DATA:\n%s\n",sick_loli_data);
                printf("--------------\n");
                fclose(fo_fi_fa_fu);
                empty_str(sick_loli_data,1000);
            }
            
            
        }
    
    
    
}
//mode=0: since
//mode=1: before
void logs_time(int mode,char* time,char* storage_dir){
    int t[6];
    sscanf(time,"%d-%d-%d %d:%d:%d",t,t+1,t+2,t+3,t+4,t+5);
    ////////////////////////
    char* temp=(char*) calloc(10000,1);
    char* list[100];
    for (int i = 0; i < 100; i++)
    {
        list[i]=(char*) calloc(256,1);
    }
    listFilesRecursively_with_depth(storage_dir,temp,1);
    
    turn_str_to_list(temp,list);
    int count=0;
    while (strcmp(list[count],"")!=0)
    {
        count++;
    }
    
    ///////////////////////////////////////////
    char* all_branch=(char*) calloc(256,1);
    char* head_branch=(char*) calloc(256,1);
    char* current_branch=(char*) calloc(256,1);
    char* previous_branch=(char*) calloc(256,1);
    strcpy(previous_branch,storage_dir);
    strcpy(all_branch,storage_dir);
    strcpy(head_branch,storage_dir);
    strcpy(current_branch,storage_dir);
    strcat(previous_branch,"\\previous_branch.txt");
    strcat(all_branch,"\\all_branch.txt");
    strcat(head_branch,"\\head_branch.txt");
    strcat(current_branch,"\\current_branch.txt");
    char* names2[100];
    int* a[100];
    for (int i = 0; i < 100; i++)
    {
        a[i]=(int*) calloc(4,6);
    }
    
    for (int i = 0; i < 100; i++)
    {
        names2[i]=(char*) calloc(256,1);
    }
    int counter2=0;
    for (int i = 0; i < count; i++)
    {
        int siz=strlen(list[i]);
        int qqqqq=0;
        int is_file=0;
        for (int j = siz-1; j >=0; j--)
        {
            if (qqqqq==1&&*(list[i]+j)=='\\')
            {
                is_file=0;
                break;
            }
            else if (qqqqq==1&&*(list[i]+j)!='\\')
            {
                is_file=1;
                break;
            }


            if (*(list[i]+j)=='.')
            {
                qqqqq=1;

            }

        }
        if (is_file&&comp_word(list[i],all_branch,strlen(all_branch))!=0&&comp_word(list[i],head_branch,strlen(head_branch))!=0&&comp_word(list[i],current_branch,strlen(current_branch))!=0&&comp_word(list[i],previous_branch,strlen(previous_branch))!=0)
        {
            strcpy(names2[counter2],list[i]);
            counter2++;
        }
        
    }
    FILE* data_file;
    for (int i = 0; i < counter2; i++)
    {
       data_file=fopen(names2[i],"r+");
       
       
       char* MUDA=(char*) calloc(256,1);
       
       fscanf(data_file,"%s\n%d-%d-%d %d:%d:%d",MUDA,a[i]+0,a[i]+1,a[i]+2,a[i]+3,a[i]+4,a[i]+5);
       fclose(data_file);
       
    }
    
    sort_file_by_date(names2,a,counter2);
    for (int i = 0; i < counter2; i++)
    {
       data_file=fopen(names2[i],"r+");
       
       
       char* MUDA=(char*) calloc(256,1);
       
       fscanf(data_file,"%s\n%d-%d-%d %d:%d:%d",MUDA,a[i]+0,a[i]+1,a[i]+2,a[i]+3,a[i]+4,a[i]+5);
       fclose(data_file);
       
    }
    if (mode==0)
    {
        
        FILE* fo_fi_fa_fu;
        for (int i = 0; i < counter2; i++)
        {
            if (compare_two_dates(t,a[i])==-1)
            {
                char* sick_loli_data=(char*) calloc(1000,1);
                fo_fi_fa_fu=fopen(names2[i],"r+");
            for (int j = 0; j < 1000; j++)
            {
                fscanf(fo_fi_fa_fu,"%c",sick_loli_data+j);
            }
            printf("DATA:\n%s\n",sick_loli_data);
            fclose(fo_fi_fa_fu);
            empty_str(sick_loli_data,1000);
            }
            
            
        }
    }
    else{
        
        FILE* fo_fi_fa_fu;
        for (int i = 0; i < counter2; i++)
        {

            if (compare_two_dates(t,a[i])==1)
            {
                char* sick_loli_data=(char*) calloc(1000,1);
            fo_fi_fa_fu=fopen(names2[i],"r+");
            for (int j = 0; j < 1000; j++)
            {
                fscanf(fo_fi_fa_fu,"%c",sick_loli_data+j);
            }
            printf("DATA:\n%s\n",sick_loli_data);
            fclose(fo_fi_fa_fu);
            empty_str(sick_loli_data,1000);
            }
        }
    }
    
}


void logs_word(char* word,char* storage_dir){
    char* temp=(char*) calloc(10000,1);
    char* list[100];
    for (int i = 0; i < 100; i++)
    {
        list[i]=(char*) calloc(256,1);
    }
    listFilesRecursively_with_depth(storage_dir,temp,1);
    
    turn_str_to_list(temp,list);
    int count=0;
    while (strcmp(list[count],"")!=0)
    {
        count++;
    }
    
    ///////////////////////////////////////////
    char* all_branch=(char*) calloc(256,1);
    char* head_branch=(char*) calloc(256,1);
    char* current_branch=(char*) calloc(256,1);
    char* previous_branch=(char*) calloc(256,1);
    strcpy(previous_branch,storage_dir);
    strcpy(all_branch,storage_dir);
    strcpy(head_branch,storage_dir);
    strcpy(current_branch,storage_dir);
    strcat(previous_branch,"\\previous_branch.txt");
    strcat(all_branch,"\\all_branch.txt");
    strcat(head_branch,"\\head_branch.txt");
    strcat(current_branch,"\\current_branch.txt");
    char* names2[100];
    char* message[100];
    for (int i = 0; i < 100; i++)
    {
        message[i]=(char*) calloc(256,1);
    }
    
    
    for (int i = 0; i < 100; i++)
    {
        names2[i]=(char*) calloc(256,1);
    }
    int* a[100];
    for (int i = 0; i < 100; i++)
    {
        a[i]=(int*) calloc(6,4);
    }
    
    int counter2=0;
    for (int i = 0; i < count; i++)
    {
        int siz=strlen(list[i]);
        int qqqqq=0;
        int is_file=0;
        for (int j = siz-1; j >=0; j--)
        {
            if (qqqqq==1&&*(list[i]+j)=='\\')
            {
                is_file=0;
                break;
            }
            else if (qqqqq==1&&*(list[i]+j)!='\\')
            {
                is_file=1;
                break;
            }


            if (*(list[i]+j)=='.')
            {
                qqqqq=1;

            }

        }
        if (is_file&&comp_word(list[i],all_branch,strlen(all_branch))!=0&&comp_word(list[i],head_branch,strlen(head_branch))!=0&&comp_word(list[i],current_branch,strlen(current_branch))!=0&&comp_word(list[i],previous_branch,strlen(previous_branch))!=0)
        {
            strcpy(names2[counter2],list[i]);
            counter2++;
        }
        
    }
    
    FILE* data_file;
    char* MUDA;
    for (int i = 0; i < counter2; i++)
    {
        printf("%s\n",names2[i]);
    }
    printf("\n\n\n");
    for (int i = 0; i < counter2; i++)
    {
       data_file=fopen(names2[i],"r+");
       
       
       MUDA=(char*) calloc(256,1);
       fscanf(data_file,"%s\n%d-%d-%d %d:%d:%d",MUDA,a[i]+0,a[i]+1,a[i]+2,a[i]+3,a[i]+4,a[i]+5);
       fclose(data_file);
       
    }
    
    sort_file_by_date(names2,a,counter2);
    for (int i = 0; i < counter2; i++)
    {
        printf("%s\n",names2[i]);
    }
    printf("\n\n\n");
    for (int i = 0; i < counter2; i++)
    {
       data_file=fopen(names2[i],"r+");
       
       
       MUDA=(char*) calloc(256,1);
       char* MUDA2=(char*) calloc(256,1);
       fscanf(data_file,"%s\n%d-%d-%d %d:%d:%d",MUDA,a[i]+0,a[i]+1,a[i]+2,a[i]+3,a[i]+4,a[i]+5);
       fseek(data_file,strlen(MUDA)+23,0);
       fgets(message[i],100,data_file);
       fclose(data_file);
       
    }
        
        FILE* fo_fi_fa_fu;
        for (int i = 0; i < counter2; i++)
        {
            fo_fi_fa_fu=fopen(names2[i],"r+");
            char* sick_loli_data=(char*) calloc(1000,1);
            if (strstr(message[i],word)!=NULL)
            {
                for (int j = 0; j < 1000; j++)
                {
                    fscanf(fo_fi_fa_fu,"%c",sick_loli_data+j);
                }
                printf("DATA:\n%s\n",sick_loli_data);
                printf("--------------\n");
                fclose(fo_fi_fa_fu);
                empty_str(sick_loli_data,1000);
            }
            
            
        }
    


}

int send_rec_to_shiz(int size_of_to_dir,char* to_dir,char* from_dir){
    ////////////////////////////////
    DIR* test =opendir(to_dir);
    if (test==NULL)
    {
        printf("the folder named: %s does not exist\n",to_dir);
        return 0;
    }
    closedir(test);
    char* y=(char*) calloc(10000,1);
    listFilesRecursively(to_dir,y);
    char* list[100];
    for (int i = 0; i < 100; i++)
    {
        list[i]=(char*) calloc(256,1);
    }
    turn_str_to_list(y,list);
    int count=0;
    while (strcmp(list[count],"")!=0)
    {
        count++;
    }
    /////////////////////////////////////////////
    
    ////////////////////////////////////////
    for (int i = 0; i < count; i++)
    {
            char* temp=(char*) calloc(256,1);
            strcpy(temp,list[i]+size_of_to_dir);
            char* new_loc=(char*) calloc(256,1);
            strcpy(new_loc,from_dir);
            strcat(new_loc,temp);
            int leng =strlen(new_loc);
            int is_file=0;
            int wwwwwwwwwwwwwwwwwwww=0;
            for (int j = leng-1; j  >=0; j--)
            {
                if (wwwwwwwwwwwwwwwwwwww==1&&*(new_loc+j)=='\\')
                {
                    break;
                }
                else if (wwwwwwwwwwwwwwwwwwww==1&&*(new_loc+j)!='\\')
                {
                    is_file=1;
                }
                
                if (*(new_loc+j)=='.')
                {
                    wwwwwwwwwwwwwwwwwwww=1;
                    
                }

            }

            if (is_file)
            {
                FILE* file=fopen(list[i],"r+");
                printf("changes_comited\n\n");
                copy_textfile_withouttxt(new_loc,file);
                fclose(file);
                
            }
            else{
                
                
                DIR* flag=opendir(new_loc);
                if (flag==NULL)
                {
                    mkdir(new_loc);
                }
                closedir(flag);
                 
            }
    }
    return 0;
}



void check_out(char* branch_name,char* storage_dir,char* shiz_dir){
    empty_shiz_dir(shiz_dir);
    empty_shiz_dir(shiz_dir);
    char* all_branches_loc=(char*) calloc(256,1);
    strcpy(all_branches_loc,storage_dir);
    strcat(all_branches_loc,"\\all_branch.txt");
    FILE* all_branch_file=fopen(all_branches_loc,"r");

    char* temp2=(char*) calloc(10000,1);
    char* rex[100];
    for (int i = 0; i < 100; i++)
    {
        rex[i]=(char*) calloc(256,1);
    }
    for (int i = 0; i < 10000; i++)
    {
        fscanf(all_branch_file,"%c",temp2+i);
    }
    turn_str_to_list(temp2,rex);
    int count2=0;
    while (strcmp(rex[count2],"")!=0)
    {
        count2++;
    }
    int is_a_branch=0;
    for (int i = 0; i < count2; i++)
    {
        if (strcmp(branch_name,rex[i])==0)
        {
            is_a_branch=1;
            break;
        }
        
    }
    char* last_branch_loc=(char*) calloc(256,1);

    if (is_a_branch==0)
    {
        char* temp33=(char*) calloc(10000,1);
        char* list[100];
        for (int i = 0; i < 100; i++)
        {
            list[i]=(char*) calloc(256,1);
        }
        listFilesRecursively_with_depth(storage_dir,temp33,1);

        turn_str_to_list(temp33,list);
        int count33=0;
        while (strcmp(list[count33],"")!=0)
        {
            count33++;
        }

        ///////////////////////////////////////////
        char* all_branch=(char*) calloc(256,1);
        char* head_branch=(char*) calloc(256,1);
        char* current_branch=(char*) calloc(256,1);
        char* previous_branch=(char*) calloc(256,1);
        strcpy(previous_branch,storage_dir);
        strcpy(all_branch,storage_dir);
        strcpy(head_branch,storage_dir);
        strcpy(current_branch,storage_dir);
        strcat(previous_branch,"\\previous_branch.txt");
        strcat(all_branch,"\\all_branch.txt");
        strcat(head_branch,"\\head_branch.txt");
        strcat(current_branch,"\\current_branch.txt");
        char* names2[100];
        char* message[100];
        for (int i = 0; i < 100; i++)
        {
            message[i]=(char*) calloc(256,1);
        }


        for (int i = 0; i < 100; i++)
        {
            names2[i]=(char*) calloc(256,1);
        }
        int counter27=0;
        for (int i = 0; i < count33; i++)
        {
            int siz=strlen(list[i]);
            int qqqqq=0;
            int is_file=0;
            for (int j = siz-1; j >=0; j--)
            {
                if (qqqqq==1&&*(list[i]+j)=='\\')
                {
                    is_file=0;
                    break;
                }
                else if (qqqqq==1&&*(list[i]+j)!='\\')
                {
                    is_file=1;
                    break;
                }


                if (*(list[i]+j)=='.')
                {
                    qqqqq=1;

                }

            }
            if (is_file&&comp_word(list[i],all_branch,strlen(all_branch))!=0&&comp_word(list[i],head_branch,strlen(head_branch))!=0&&comp_word(list[i],current_branch,strlen(current_branch))!=0&&comp_word(list[i],previous_branch,strlen(previous_branch))!=0)
            {
                strcpy(names2[counter27],list[i]);
                counter27++;
            }

        }

        for (int i = 0; i < counter27; i++)
        {
            FILE* fool=fopen(names2[i],"r");
            unsigned char* hash33=(unsigned char*) calloc(16,1);
            fseek(fool,0,2);
            int hy=0;
            char cum;
            int loz=ftell(fool);
            while (hy<=5)
            {
                fseek(fool,loz,0);
                fscanf(fool,"%c",&cum);
                if (cum=='\n')
                {
                    hy++;
                }
                loz--;
            }            
            
            
            for (int vv = 0; vv < 100; vv++)
            {
                fseek(fool,loz+2,0);
                fscanf(fool,"%c",hash33+vv);
                loz++;
                if (*(hash33+vv)=='\n')
                {
                    break;
                }
                
            }
            
            
            if (comp_word(hash33,branch_name,strlen(branch_name))==0)
            {
                copy(last_branch_loc,names2[i],strlen(names2[i])-4);
                break;
            }

        }
    


    }
    else{
         /////////////////////////////////////
    char* temp=(char*) calloc(10000,1);
    char* files_shiz[100];
    for (int i = 0; i < 100; i++)
    {
        files_shiz[i]=(char*) calloc(256,1);
    }
    listFilesRecursively_with_depth(shiz_dir,temp,1);
    turn_str_to_list(temp,files_shiz);
    int count=0;
    while (strcmp(files_shiz[count],"")!=0)
    {
        count++;
    }
    free(temp);
    //////////////////////////////////
    char* shiz_folder_dir=(char*) calloc(256,1);
    strcpy(shiz_folder_dir,shiz_dir);
    strcat(shiz_folder_dir,"\\.shiz");
    for (int i = 0; i < count; i++)
    {
        if (strcmp(shiz_folder_dir,files_shiz[i])!=0)
        {
            int siz=strlen(files_shiz[i]);
            int qqqqq=0;
            int is_file=0;
            for (int j = siz-1; j >=0; j--)
            {
                if (qqqqq==1&&*(files_shiz[i]+j)=='\\')
                {
                    is_file=0;
                    break;
                }
                else if (qqqqq==1&&*(files_shiz[i]+j)!='\\')
                {
                    is_file=1;
                    break;
                }


                if (*(files_shiz[i]+j)=='.')
                {
                    qqqqq=1;

                }

            }
            if (is_file)
            {
                remove(files_shiz[i]);
            }
            else{
                empty_dir(files_shiz[i]);
                empty_dir(files_shiz[i]);
                empty_dir(files_shiz[i]);
                rmdir(files_shiz[i]);

            }
        
        
        }
        
    }
    ///////////////////////////////////
    // restoring from storage:
    
    char* test=(char*) calloc(256,1);
    strcpy(test,storage_dir);
    strcat(test,"\\");
    strcat(test,branch_name);
    strcat(test,"_");
    int lengt=strlen(test);
    FILE* test_file;
    int num=0;
    do
    {
        sprintf(test+lengt,"%d",num);
        strcat(test,".txt");
        test_file=fopen(test,"r");
        num++;
    } while (test_file!=NULL);
    strcpy(last_branch_loc,storage_dir);
    strcat(last_branch_loc,"\\");
    strcat(last_branch_loc,branch_name);
    strcat(last_branch_loc,"_");
    int r=strlen(last_branch_loc);
    sprintf(last_branch_loc+r,"%d",(num-2));
    printf("%s\n",last_branch_loc);
    printf("%s\n",shiz_dir);
    
    }
    
    send_rec_to_shiz(strlen(last_branch_loc),last_branch_loc,shiz_dir);



   
}


void n_before_head(char* output,int n,char* storage_dir){
    char* prev=(char*) calloc(256,1);
    char* prev_loc=(char*) calloc(256,1);
    strcpy(prev_loc,storage_dir);
    strcat(prev_loc,"\\previous_branch.txt");
    if (n==1)
    {
        FILE* fole=fopen(prev_loc,"r");
        fscanf(fole,"%s",prev);
        if (strcmp(prev,"NULL")==0)
        {
            printf("your given n is bigger then number of commits\n");
            return;
        }
        strcpy(output,storage_dir);
        strcat(output,"\\");
        strcat(output,prev);

    }
    else{
        for (int i = 0; i < n-1; i++)
        {
            FILE* fole=fopen(prev_loc,"r");
            fscanf(fole,"%s",prev);
            if (strcmp(prev,"NULL")==0)
            {
                printf("your given n is bigger then number of commits\n");
                break;
            }

            empty_str(prev_loc,256);
            strcpy(prev_loc,storage_dir);
            strcat(prev_loc,"\\");
            strcat(prev_loc,prev);
            strcat(prev_loc,".txt");
            empty_str(prev,256);
            fclose(fole);
        }
        copy(output,prev_loc,strlen(prev_loc)-4);
    }
    
    


}




void revert_with_out_commit(char* pos_of_wanted_commit_to_revert,char* commit_id,char* storage_dir,char* shiz_dir){
    char* last_branch_loc=(char*) calloc(256,1);
    char* temp33=(char*) calloc(10000,1);
    char* list[100];
    for (int i = 0; i < 100; i++)
    {
        list[i]=(char*) calloc(256,1);
    }
    listFilesRecursively_with_depth(storage_dir,temp33,1);
    turn_str_to_list(temp33,list);
    int count33=0;
    while (strcmp(list[count33],"")!=0)
    {
        count33++;
    }
    ///////////////////////////////////////////
    char* all_branch=(char*) calloc(256,1);
    char* head_branch=(char*) calloc(256,1);
    char* current_branch=(char*) calloc(256,1);
    char* previous_branch=(char*) calloc(256,1);
    strcpy(previous_branch,storage_dir);
    strcpy(all_branch,storage_dir);
    strcpy(head_branch,storage_dir);
    strcpy(current_branch,storage_dir);
    strcat(previous_branch,"\\previous_branch.txt");
    strcat(all_branch,"\\all_branch.txt");
    strcat(head_branch,"\\head_branch.txt");
    strcat(current_branch,"\\current_branch.txt");
    char* names2[100];
    char* message[100];
    for (int i = 0; i < 100; i++)
    {
        message[i]=(char*) calloc(256,1);
    }
    for (int i = 0; i < 100; i++)
    {
        names2[i]=(char*) calloc(256,1);
    }
    int counter27=0;
    for (int i = 0; i < count33; i++)
    {
        int siz=strlen(list[i]);
        int qqqqq=0;
        int is_file=0;
        for (int j = siz-1; j >=0; j--)
        {
            if (qqqqq==1&&*(list[i]+j)=='\\')
            {
                is_file=0;
                break;
            }
            else if (qqqqq==1&&*(list[i]+j)!='\\')
            {
                is_file=1;
                break;
            }
            if (*(list[i]+j)=='.')
            {
                qqqqq=1;
            }
        }
        if (is_file&&comp_word(list[i],all_branch,strlen(all_branch))!=0&&comp_word(list[i],head_branch,strlen(head_branch))!=0&&comp_word(list[i],current_branch,strlen(current_branch))!=0&&comp_word(list[i],previous_branch,strlen(previous_branch))!=0)
        {
            strcpy(names2[counter27],list[i]);
            counter27++;
        }
    }
    for (int i = 0; i < counter27; i++)
    {
        FILE* fool=fopen(names2[i],"r");
        char* tomp=(char*) calloc(256,1);
        char* tomp2=(char*) calloc(256,1);
        char* tomp3=(char*) calloc(256,1);
        int a[6];
        char* hash33=(char*) calloc(16,1);
        fscanf(fool,"%s\n%d-%d-%d %d:%d:%d\n%s\n%s\n%s\n",tomp,a,a+1,a+2,a+3,a+4,a+5,tomp2,tomp3,hash33);
        if (strcmp(hash33,commit_id)==0)
        {
            copy(last_branch_loc,names2[i],strlen(names2[i])-4);
            break;
        }
    }

    //last branch loc is the one with given id
    strcpy(pos_of_wanted_commit_to_revert,last_branch_loc);
    send_rec_to_shiz(strlen(last_branch_loc),last_branch_loc,shiz_dir);
}


void find_line(char* out,FILE* file, int line){

    int x=0;
    char w;
    int cum=0;
    int wasn=1;
    for (int i = 0; i < 10000; i++)
    {
        fseek(file,i,0);
        fscanf(file,"%c",&w);

        if (w=='\n')
        {
            wasn=1;
            x++;
            cum=i+1;
        }
        else if (wasn==1&&w!='n')
        {
            //cum=i;
            wasn=0;
        }
        
        if (x==line*2)
        {
            break;
        }
        
    }
    int o=0;
    for (int i = 0; i < 1000; i++)
    {
        fseek(file,cum+i,0);
        fscanf(file,"%c",&w);
        *(out+o)=w;
        o++;
        if (w=='\n')
        {
            break;
        }
        
    }
    



}


int line_size(char *A,int start_pos){
    int i=0;
    while (1)
    {
        
        if (*(A+i+start_pos)=='\n'||*(A+i+start_pos)=='\0')
        {
            break;
        }
        
        i++;
    }
    return i;
}
//start position of a line knowing start position of another line
// and line distance between them
int line_pos(char *A,int start_pos,int amount){
    int ret_val=start_pos;
    for (int i = 0; i < amount; i++)
    {
        ret_val+=line_size(A,ret_val)+1;
    }
    return ret_val;

}

void turn_line_to_list(char* string,char* list[]){
    int pos=0;
    int leng;
    int i=0;
    do
    {
        leng=line_size(string,pos);
        copy(list[i],string+pos,leng);
        i++;
        pos=line_pos(string,pos,1);
    } while (leng>0);
}

void turn_str_to_list2(char* string,char* list[]){
    int pos=0;
    int leng;
    for(int w; w<90;w++)
    {
        leng=word_size(string,pos);
        copy(list[w],string+pos,leng);
        
        pos=word_pos(string,pos,1);
    }
}

void read_file_without_nullspace(char* out,FILE* file){
    char* temp=(char*) calloc(10000,1);
    int did_find_space=0;
    int back=0;
    int counter=0;
    char x;
    for (int i = 0; i < 10000; i++)
    {
        fseek(file,i,0);
        fscanf(file,"%c",&x);
        if (x=='\n')
        {
            did_find_space=1;
        }
        else{
            back=0;
            did_find_space=0;
        }
        if (did_find_space==0)
        {
            *(temp+counter)=x;
            counter++;
        }
        else if (did_find_space==1&&back==0)
        {
            back=1;
            *(temp+counter)=x;
            counter++;
        }
        
    }
    
    for (int i = 0; i < counter; i++)
    {
        *(out+i)=*(temp+i);
    }
    
    fseek(file,0,0);

}

void diff(char* file_loc1,char* file_loc2){
    
    int leng =strlen(file_loc1);
    int is_file=0;
    int wwwwwwwwwwwwwwwwwwww=0;
    for (int j = leng-1; j  >=0; j--)
    {
        if (wwwwwwwwwwwwwwwwwwww==1&&*(file_loc1+j)=='\\')
        {
            break;
        }
        else if (wwwwwwwwwwwwwwwwwwww==1&&*(file_loc1+j)!='\\')
        {
            is_file=1;
        }
        
        if (*(file_loc1+j)=='.')
        {
            wwwwwwwwwwwwwwwwwwww=1;
            
        }
    }

    int leng2 =strlen(file_loc2);
    int is_file2=0;
    int wwwwwwwwwwwwwwwwwwww2=0;
    for (int j = leng-1; j  >=0; j--)
    {
        if (wwwwwwwwwwwwwwwwwwww2==1&&*(file_loc2+j)=='\\')
        {
            break;
        }
        else if (wwwwwwwwwwwwwwwwwwww2==1&&*(file_loc2+j)!='\\')
        {
            is_file2=1;
        }
        
        if (*(file_loc2+j)=='.')
        {
            wwwwwwwwwwwwwwwwwwww2=1;
            
        }
    }
    if (is_file==0||is_file2==0)
    {
        printf("not file\n");
        return;
    }
    
    FILE* f1=fopen(file_loc1,"r+");
    FILE* f2=fopen(file_loc2,"r+");
    char* file1=(char*) calloc(10000,1);
    char* file2=(char*) calloc(10000,1);
    char* bussy1=(char*) calloc(10000,1);
    char* bussy2=(char*) calloc(10000,1);
    for (int i = 0; i < 10000; i++)
    {
        fseek(f1,i,0);
        fscanf(f1,"%c",bussy1+i);
    }
    for (int i = 0; i < 10000; i++)
    {
        fseek(f2,i,0);
        fscanf(f2,"%c",bussy2+i);
    }
    fseek(f1,0,0);
    fseek(f2,0,0);
    read_file_without_nullspace(file1,f1);
    read_file_without_nullspace(file2,f2);
    char* lines1[30];
    char* lines2[30];
    char* gyalines1[100];
    char* gyalines2[100];
    for (int i = 0; i < 30; i++)
    {
        lines1[i]=(char*) calloc(10000,1);
        lines2[i]=(char*) calloc(10000,1);
    }
    for (int i = 0; i < 100; i++)
    {
        gyalines1[i]=(char*) calloc(1000,1);
        gyalines2[i]=(char*) calloc(1000,1);
    }

    turn_line_to_list(file1,lines1);
    turn_line_to_list(file2,lines2);

    turn_str_to_list2(bussy1,gyalines1);
    turn_str_to_list2(bussy2,gyalines2);

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(lines1[i],lines2[i])!=0)
        {
            int line1=0;
            int line2=0;
            for (int j = 0; j < 100; j++)
            {
                if (strcmp(lines1[i],gyalines1[j])==0)
                {
                   line1=j/2-2;
                   break;
                }
                
            }
            for (int j = 0; j < 100; j++)
            {
                if (strcmp(lines2[i],gyalines2[j])==0)
                {
                   line2=j/2-2;
                   break;
                }
                
            }
            printf(KMAG"<<<<<<<<\n"RESET);
            printf(KBLU"%s-%d\n"RESET,file_loc1,line1);
            
            
            printf(KRED"%s\n"RESET,lines1[i]);
            printf(KBLU"%s-%d\n"RESET,file_loc2,i+1);
            printf(KRED"%s\n"RESET,lines2[i]);
            printf(KMAG">>>>>>>>\n\n"RESET);
        }
    }
}


void diff_commits(char* id1,char* id2,char* storage_dir){
    
    char* last_branch_loc1=(char*) calloc(256,1);

    {
        char* temp33=(char*) calloc(10000,1);
        char* list[100];
        for (int i = 0; i < 100; i++)
        {
            list[i]=(char*) calloc(256,1);
        }
        listFilesRecursively_with_depth(storage_dir,temp33,1);

        turn_str_to_list(temp33,list);
        int count33=0;
        while (strcmp(list[count33],"")!=0)
        {
            count33++;
        }

        ///////////////////////////////////////////
        char* all_branch=(char*) calloc(256,1);
        char* head_branch=(char*) calloc(256,1);
        char* current_branch=(char*) calloc(256,1);
        char* previous_branch=(char*) calloc(256,1);
        strcpy(previous_branch,storage_dir);
        strcpy(all_branch,storage_dir);
        strcpy(head_branch,storage_dir);
        strcpy(current_branch,storage_dir);
        strcat(previous_branch,"\\previous_branch.txt");
        strcat(all_branch,"\\all_branch.txt");
        strcat(head_branch,"\\head_branch.txt");
        strcat(current_branch,"\\current_branch.txt");
        char* names2[100];
        


        for (int i = 0; i < 100; i++)
        {
            names2[i]=(char*) calloc(256,1);
        }
        int counter27=0;
        for (int i = 0; i < count33; i++)
        {
            int siz=strlen(list[i]);
            int qqqqq=0;
            int is_file=0;
            for (int j = siz-1; j >=0; j--)
            {
                if (qqqqq==1&&*(list[i]+j)=='\\')
                {
                    is_file=0;
                    break;
                }
                else if (qqqqq==1&&*(list[i]+j)!='\\')
                {
                    is_file=1;
                    break;
                }


                if (*(list[i]+j)=='.')
                {
                    qqqqq=1;

                }

            }
            if (is_file&&comp_word(list[i],all_branch,strlen(all_branch))!=0&&comp_word(list[i],head_branch,strlen(head_branch))!=0&&comp_word(list[i],current_branch,strlen(current_branch))!=0&&comp_word(list[i],previous_branch,strlen(previous_branch))!=0)
            {
                strcpy(names2[counter27],list[i]);
                counter27++;
            }

        }

        for (int i = 0; i < counter27; i++)
        {
            FILE* fool=fopen(names2[i],"r");
            unsigned char* hash33=(unsigned char*) calloc(16,1);
            fseek(fool,0,2);
            int hy=0;
            char cum;
            int loz=ftell(fool);
            while (hy<=4)
            {
                
                fseek(fool,loz,0);
                fscanf(fool,"%c",&cum);
                if (cum=='\n')
                {
                    hy++;
                }
                loz--;
            }            
            
            
            for (int vv = 0; vv < 100; vv++)
            {
                fseek(fool,loz+2,0);
                fscanf(fool,"%c",hash33+vv);
                loz++;
                if (*(hash33+vv)=='\n')
                {
                    break;
                }
                
            }
            
            if (comp_word(hash33,id1,strlen(id1))==0)
            {
                copy(last_branch_loc1,names2[i],strlen(names2[i])-4);
                break;
            }
            fclose(fool);
        }
    }
    char* last_branch_loc2=(char*) calloc(256,1);

    {
        char* temp33=(char*) calloc(10000,1);
        char* list[100];
        for (int i = 0; i < 100; i++)
        {
            list[i]=(char*) calloc(256,1);
        }
        listFilesRecursively_with_depth(storage_dir,temp33,1);

        turn_str_to_list(temp33,list);
        int count33=0;
        while (strcmp(list[count33],"")!=0)
        {
            count33++;
        }

        ///////////////////////////////////////////
        char* all_branch=(char*) calloc(256,1);
        char* head_branch=(char*) calloc(256,1);
        char* current_branch=(char*) calloc(256,1);
        char* previous_branch=(char*) calloc(256,1);
        strcpy(previous_branch,storage_dir);
        strcpy(all_branch,storage_dir);
        strcpy(head_branch,storage_dir);
        strcpy(current_branch,storage_dir);
        strcat(previous_branch,"\\previous_branch.txt");
        strcat(all_branch,"\\all_branch.txt");
        strcat(head_branch,"\\head_branch.txt");
        strcat(current_branch,"\\current_branch.txt");
        char* names2[100];
        char* message[100];
        for (int i = 0; i < 100; i++)
        {
            message[i]=(char*) calloc(256,1);
        }


        for (int i = 0; i < 100; i++)
        {
            names2[i]=(char*) calloc(256,1);
        }
        int counter27=0;
        for (int i = 0; i < count33; i++)
        {
            int siz=strlen(list[i]);
            int qqqqq=0;
            int is_file=0;
            for (int j = siz-1; j >=0; j--)
            {
                if (qqqqq==1&&*(list[i]+j)=='\\')
                {
                    is_file=0;
                    break;
                }
                else if (qqqqq==1&&*(list[i]+j)!='\\')
                {
                    is_file=1;
                    break;
                }


                if (*(list[i]+j)=='.')
                {
                    qqqqq=1;

                }

            }
            if (is_file&&comp_word(list[i],all_branch,strlen(all_branch))!=0&&comp_word(list[i],head_branch,strlen(head_branch))!=0&&comp_word(list[i],current_branch,strlen(current_branch))!=0&&comp_word(list[i],previous_branch,strlen(previous_branch))!=0)
            {
                strcpy(names2[counter27],list[i]);
                counter27++;
            }

        }

        for (int i = 0; i < counter27; i++)
        {
            FILE* fool=fopen(names2[i],"r");
            unsigned char* hash33=(unsigned char*) calloc(16,1);
            fseek(fool,0,2);
            int hy=0;
            char cum;
            int loz=ftell(fool);
            while (hy<=5)
            {
                fseek(fool,loz,0);
                fscanf(fool,"%c",&cum);
                if (cum=='\n')
                {
                    hy++;
                }
                loz--;
            }            
            
            
            for (int vv = 0; vv < 100; vv++)
            {
                fseek(fool,loz+2,0);
                fscanf(fool,"%c",hash33+vv);
                loz++;
                if (*(hash33+vv)=='\n')
                {
                    break;
                }
                
            }
            
            if (comp_word(hash33,id2,strlen(id2))==0)
            {
                copy(last_branch_loc2,names2[i],strlen(names2[i])-4);
                break;
            }

        }
    }

    printf("%s\n%s\n",last_branch_loc1,last_branch_loc2);
    ///////////////////////
    char* locs1[100];
    char* locs2[100];
    char* f=(char*) calloc(10000,1);
    char* z=(char*) calloc(10000,1);

    for (int i = 0; i < 100; i++)
    {
        locs1[i]=(char*) calloc(256,1);
        locs2[i]=(char*) calloc(256,1);
    }
    listFilesRecursively(last_branch_loc1,f);
    listFilesRecursively(last_branch_loc2,z);
    turn_str_to_list(f,locs1);
    turn_str_to_list(z,locs2);
    int count3=0;
    while (strcmp(locs1[count3],"")!=0)
    {
        count3++;
    }
    int count4=0;
    while (strcmp(locs2[count4],"")!=0)
    {
        count4++;
    }
    
    for (int i = 0; i < count3; i++)
    {
        int siz=strlen(locs2[i]);
            int qqqqq=0;
            int is_file=0;
            for (int j = siz-1; j >=0; j--)
            {
                if (qqqqq==1&&*(locs2[i]+j)=='\\')
                {
                    is_file=0;
                    break;
                }
                else if (qqqqq==1&&*(locs2[i]+j)!='\\')
                {
                    is_file=1;
                    break;
                }


                if (*(locs2[i]+j)=='.')
                {
                    qqqqq=1;

                }

            }
            
        for (int j = 0; j < count4; j++)
        {
            
            if (is_file==1&&strcmp(locs1[i]+strlen(last_branch_loc1),locs2[j]+strlen(last_branch_loc1))==0)
            {
                diff(locs1[i],locs2[j]);
                break;
            }
        }
        
        
        
    }
    
    
    

}


int dis_to_base(char* commit_name,char* storage_dir){
    char* prev=(char*) calloc(256,1);
    char* prev_loc=(char*) calloc(256,1);
    strcpy(prev_loc,storage_dir);
    strcat(prev_loc,"\\");
    strcat(prev_loc,commit_name);
    strcat(prev_loc,".txt");
    char* temp=(char*) calloc(256,1);
    int n =0;
    while (1)
    {
        FILE* file=fopen(prev_loc,"r");
        fscanf(file,"%s",temp);
        if (strcmp(temp,"NULL")==0)
        {
            break;
        }
        empty_str(prev_loc,256);
        strcpy(prev_loc,storage_dir);
        strcat(prev_loc,"\\");
        strcat(prev_loc,temp);
        strcat(prev_loc,".txt");
        empty_str(temp,256);
        fclose(file);
        n++;
    }
    return n;
    
    
    


}

int diff2(char* file_loc1,char* file_loc2){
    
    int leng =strlen(file_loc1);
    int is_file=0;
    int wwwwwwwwwwwwwwwwwwww=0;
    for (int j = leng-1; j  >=0; j--)
    {
        if (wwwwwwwwwwwwwwwwwwww==1&&*(file_loc1+j)=='\\')
        {
            break;
        }
        else if (wwwwwwwwwwwwwwwwwwww==1&&*(file_loc1+j)!='\\')
        {
            is_file=1;
        }
        
        if (*(file_loc1+j)=='.')
        {
            wwwwwwwwwwwwwwwwwwww=1;
            
        }
    }

    int leng2 =strlen(file_loc2);
    int is_file2=0;
    int wwwwwwwwwwwwwwwwwwww2=0;
    for (int j = leng-1; j  >=0; j--)
    {
        if (wwwwwwwwwwwwwwwwwwww2==1&&*(file_loc2+j)=='\\')
        {
            break;
        }
        else if (wwwwwwwwwwwwwwwwwwww2==1&&*(file_loc2+j)!='\\')
        {
            is_file2=1;
        }
        
        if (*(file_loc2+j)=='.')
        {
            wwwwwwwwwwwwwwwwwwww2=1;
            
        }
    }
    if (is_file==0||is_file2==0)
    {
        printf("not file\n");
        return -1;
    }
    
    FILE* f1=fopen(file_loc1,"r+");
    FILE* f2=fopen(file_loc2,"r+");
    char* file1=(char*) calloc(10000,1);
    char* file2=(char*) calloc(10000,1);
    char* bussy1=(char*) calloc(10000,1);
    char* bussy2=(char*) calloc(10000,1);
    for (int i = 0; i < 10000; i++)
    {
        fseek(f1,i,0);
        fscanf(f1,"%c",bussy1+i);
    }
    for (int i = 0; i < 10000; i++)
    {
        fseek(f2,i,0);
        fscanf(f2,"%c",bussy2+i);
    }
    fseek(f1,0,0);
    fseek(f2,0,0);
    read_file_without_nullspace(file1,f1);
    read_file_without_nullspace(file2,f2);
    char* lines1[30];
    char* lines2[30];
    char* gyalines1[100];
    char* gyalines2[100];
    for (int i = 0; i < 30; i++)
    {
        lines1[i]=(char*) calloc(10000,1);
        lines2[i]=(char*) calloc(10000,1);
    }
    for (int i = 0; i < 100; i++)
    {
        gyalines1[i]=(char*) calloc(1000,1);
        gyalines2[i]=(char*) calloc(1000,1);
    }

    turn_line_to_list(file1,lines1);
    turn_line_to_list(file2,lines2);

    turn_str_to_list2(bussy1,gyalines1);
    turn_str_to_list2(bussy2,gyalines2);
    int ret_val=0;
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(lines1[i],lines2[i])!=0)
        {
            ret_val=23;
            int line1=0;
            int line2=0;
            for (int j = 0; j < 100; j++)
            {
                if (strcmp(lines1[i],gyalines1[j])==0)
                {
                   line1=j/2-2;
                   break;
                }
                
            }
            for (int j = 0; j < 100; j++)
            {
                if (strcmp(lines2[i],gyalines2[j])==0)
                {
                   line2=j/2-2;
                   break;
                }
                
            }
            printf(KMAG"<<<<<<<<\n"RESET);
            printf(KBLU"%s-%d\n"RESET,file_loc1,line1);
            
            
            printf(KRED"%s\n"RESET,lines1[i]);
            printf(KBLU"%s-%d\n"RESET,file_loc2,i+1);
            printf(KRED"%s\n"RESET,lines2[i]);
            printf(KMAG">>>>>>>>\n\n"RESET);
        }
    }
    return ret_val;
}


void tree(char* storage_dir){
    char* temp=(char*) calloc(10000,1);
    char* list[100];
    for (int i = 0; i < 100; i++)
    {
        list[i]=(char*) calloc(256,1);
    }
    listFilesRecursively_with_depth(storage_dir,temp,1);
    
    turn_str_to_list(temp,list);
    int count=0;
    while (strcmp(list[count],"")!=0)
    {
        count++;
    }
    ////////////////////////////////////////////////////
    char* show_all_branches=(char*) calloc(256,1);
    strcpy(show_all_branches,storage_dir);
    strcat(show_all_branches,"//all_branch.txt");
    char* se=(char*) calloc(10000,1);
    FILE* file=fopen(show_all_branches,"r");
    char* w[10];
    for (int i = 0; i < 10; i++)
    {
        w[i]=(char*) calloc(256,1);
    }
    for (int i = 0; i < 10000; i++)
    {
        fseek(file,i,0);
        fscanf(file,"%c",se+i);
    }
    turn_str_to_list(se,w);
    int count33=0;
    while (strcmp(w[count33],"")!=0)
    {
        count33++;
    }
    char* all_branch=(char*) calloc(256,1);
    char* head_branch=(char*) calloc(256,1);
    char* current_branch=(char*) calloc(256,1);
    char* previous_branch=(char*) calloc(256,1);
    strcpy(previous_branch,storage_dir);
    strcpy(all_branch,storage_dir);
    strcpy(head_branch,storage_dir);
    strcpy(current_branch,storage_dir);
    strcat(previous_branch,"\\previous_branch.txt");
    strcat(all_branch,"\\all_branch.txt");
    strcat(head_branch,"\\head_branch.txt");
    strcat(current_branch,"\\current_branch.txt");
    char* names2[100];
    int* a[100];
    for (int i = 0; i < 100; i++)
    {
        a[i]=(int*) calloc(4,6);
    }
    
    for (int i = 0; i < 100; i++)
    {
        names2[i]=(char*) calloc(256,1);
    }
    int counter2=0;
    for (int i = 0; i < count; i++)
    {
        int siz=strlen(list[i]);
        int qqqqq=0;
        int is_file=0;
        for (int j = siz-1; j >=0; j--)
        {
            if (qqqqq==1&&*(list[i]+j)=='\\')
            {
                is_file=0;
                break;
            }
            else if (qqqqq==1&&*(list[i]+j)!='\\')
            {
                is_file=1;
                break;
            }


            if (*(list[i]+j)=='.')
            {
                qqqqq=1;

            }

        }
        if (is_file&&comp_word(list[i],all_branch,strlen(all_branch))!=0&&comp_word(list[i],head_branch,strlen(head_branch))!=0&&comp_word(list[i],current_branch,strlen(current_branch))!=0&&comp_word(list[i],previous_branch,strlen(previous_branch))!=0)
        {
            strcpy(names2[counter2],list[i]);
            counter2++;
        }
        
    }
    
    int start;
    int finish=-1;
    char* side=(char*) calloc(256,1);
    strcpy(side,storage_dir);
    strcat(side,"\\");
    strcat(side,w[count33-1]);
    strcat(side,"_0.txt");
    FILE* idontknowman=fopen(side,"r+");
    char* what=(char*) calloc(256,1);
    fscanf(idontknowman,"%s",what);
    int this_is_bad;
    for (int i = 0; i < 50; i++)
    {
        if (*(what+i)=='_')
        {
            this_is_bad=i;
            break;
        }
        
    }
    start=decipher(strlen(what)-this_is_bad,what+this_is_bad+1);
    start++;
    int tot=0;
    int s_num=0;
    int m_num=0;
    for (int i = 0; i < counter2; i++)
    {
        if (i==0)
        {
            printf("NULL\n");
        }
        
        char* out_main=(char*) calloc(256,1);
        char* out_side=(char*) calloc(256,1);
        strcpy(out_main,"main_");
        strcpy(out_side,"side_");
        if (tot>counter2)
        {
            break;
        }
        
        if (i==finish)
        {
            sprintf(out_main+strlen(out_main),"%d",m_num);
            m_num++;
            sprintf(out_side+strlen(out_side),"%d",s_num);
            s_num++;
            printf("|\n|\n%s--%s\n",out_main,out_side);
            tot+=2;
        }
        else if (i==start)
        {
            sprintf(out_main+strlen(out_main),"%d",m_num);
            m_num++;
            sprintf(out_side+strlen(out_side),"%d",s_num);
            s_num++;
            printf("|\n|\n%s--%s\n",out_main,out_side);
            tot+=2;
        }
        else if (i>start)
        {
            if (finish==-1)
            {
                sprintf(out_main+strlen(out_main),"%d",m_num);
                m_num++;
                sprintf(out_side+strlen(out_side),"%d",s_num);
                s_num++;
                printf("|       |\n|       |\n%s  %s\n",out_main,out_side);
                tot+=2;
            }
            else{
                if (i<finish)
                {
                    sprintf(out_main+strlen(out_main),"%d",m_num);
                    m_num++;
                    sprintf(out_side+strlen(out_side),"%d",s_num);
                    s_num++;
                    printf("|       |\n|       |\n%s  %s\n",out_main,out_side);
                    tot+=2;
                }
                
            }
            
        }
        else if (i==0)
        {
            sprintf(out_main+strlen(out_main),"%d",m_num);
            m_num++;
            printf("|\n|\n%s\n",out_main);
            tot++;
        }
        
        else{
            sprintf(out_main+strlen(out_main),"%d",m_num);
            m_num++;
            printf("|\n|\n%s\n",out_main);
            tot++;
        }
        empty_str(out_main,256);
        empty_str(out_side,256);
    }
    
    
    
}

int merge(char* branch_1,char* branch_2,char* storage_dir,char* stage_dir,char* shiz_dir){
    if (number_files(stage_dir)!=0)
    {
        printf("uncommited changes\n");
        return -1;
    }
    char* all_branch_loc=(char*) calloc(256,1);
    strcpy(all_branch_loc,storage_dir);
    strcat(all_branch_loc,"\\all_branch.txt");
    FILE* all_branches=fopen(all_branch_loc,"r+");
    char* totnotadick=(char*) calloc(1000,1);
    for (int i = 0; i < 1000; i++)
    {
        fseek(all_branches,i,0);
        fscanf(all_branches,"%c",totnotadick+i);
    }
    char* alldontknow[20];
    for (int i = 0; i < 20; i++)
    {
        alldontknow[i]=(char*) calloc(256,1);
    }
    turn_str_to_list(totnotadick,alldontknow);
    int cosine=0;

    while (strcmp(alldontknow[cosine],"")!=0)
    {
        cosine++;
    }
    int order=0;
    for (int i = 0; i < cosine; i++)
    {
        if (strcmp(branch_1,alldontknow[i])==0)
        {
            break;
        }
        if (strcmp(branch_2,alldontknow[i])==0)
        {
            order=1;
            break;
        }
    }
    
    


    char* last_branch_loc=(char*) calloc(256,1);
    char* test=(char*) calloc(256,1);
    strcpy(test,storage_dir);
    strcat(test,"\\");
    strcat(test,branch_1);
    strcat(test,"_");
    int lengt=strlen(test);
    FILE* test_file;
    int num=0;
    do
    {
        sprintf(test+lengt,"%d",num);
        strcat(test,".txt");
        test_file=fopen(test,"r");
        num++;
    } while (test_file!=NULL);
    strcpy(last_branch_loc,storage_dir);
    strcat(last_branch_loc,"\\");
    strcat(last_branch_loc,branch_1);
    strcat(last_branch_loc,"_");
    int r=strlen(last_branch_loc);
    sprintf(last_branch_loc+r,"%d",(num-2));
    
    ///////////////
    
    char* last_branch_loc2=(char*) calloc(256,1);
    char* test2=(char*) calloc(256,1);
    strcpy(test2,storage_dir);
    strcat(test2,"\\");
    strcat(test2,branch_1);
    strcat(test2,"_");
    lengt=strlen(test2);
    FILE* test_file2;
    int num2=0;
    do
    {
        sprintf(test2+lengt,"%d",num2);
        strcat(test2,".txt");
        test_file2=fopen(test2,"r");
        num2++;
    } while (test_file2!=NULL);
    strcpy(last_branch_loc2,storage_dir);
    strcat(last_branch_loc2,"\\");
    strcat(last_branch_loc2,branch_2);
    strcat(last_branch_loc2,"_");
    r=strlen(last_branch_loc2);
    sprintf(last_branch_loc2+r,"%d",(num2+1));
    
    
    char* files1[100];
    char* files2[100];
    char* faa1=(char*) calloc(10000,1);
    char* faa2=(char*) calloc(10000,1);
    for (int i = 0; i < 100; i++)
    {
        files1[i]=(char*) calloc(256,1);
        files2[i]=(char*) calloc(256,1);
    }
    listFilesRecursively(last_branch_loc,faa1);
    listFilesRecursively(last_branch_loc2,faa2);
    turn_str_to_list(faa1,files1);
    turn_str_to_list(faa2,files2);
    int did=1;
    for (int i = 0; i < number_files(last_branch_loc2); i++)
    {
        
        for (int j = 0; j< number_files(last_branch_loc); j++)
        {
            if (strcmp(files2[i]+strlen(test2)-4,files1[j]+strlen(test)-4)==0)
            {
                did =diff2(files2[i],files1[j]);
                break;
            }
        }   
        
        
    }
    if (did==1||did==0)
    {

        send_rec_to_shiz(strlen(last_branch_loc),last_branch_loc,stage_dir);
        send_rec_to_shiz(strlen(last_branch_loc2),last_branch_loc2,stage_dir);
        
        
    }
    
    return order;

}

void tag(char* storage_dir,char* message,char* tag_name,char* commit_id,char* auth_name,char* email){
    char* sex_loc=(char*) calloc(10000,1);
    char* gay=(char*) calloc(256,1);
    strcpy(gay,storage_dir);
    strcat(gay,"\\tag");
    listFilesRecursively(gay,sex_loc);
    char* tags_loc[20];
    for (int i = 0; i < 20; i++)
    {
        tags_loc[i]=(char*) calloc(256,1);
    }
    turn_str_to_list(sex_loc,tags_loc);
    int count=0;

    while (strcmp(tags_loc[count],"")!=0)
    {
        count++;
    }
    ///////////////////////////////////////
    int possible=1;
    for (int i = 0; i < count; i++)
    {
        FILE* fole=fopen(tags_loc[i],"r");
        char* name=(char*) calloc(256,1);
        fscanf(fole,"%s\n",name);
        if (strcmp(name,tag_name)==0)
        {
            possible=0;
            break;
        }
        fclose(fole);
    }
    
    if (possible)
    {
        time_t t = time(NULL);
        struct tm time = *localtime(&t);
        strcat(gay,"\\");
        strcat(gay,"num.txt");
        FILE* num=fopen(gay,"r+");
        char numssss;
        fscanf(num,"%c",&numssss);
        char tesrix=(char)((int)numssss+1);
        fseek(num,0,0);
        fprintf(num,"%c",tesrix);
        fclose(num);
        empty_str(gay,256);
        strcpy(gay,storage_dir);
        strcat(gay,"\\tag");
        strcat(gay,"\\");
        char* sss=(char*) calloc(1,1);
        *sss=numssss;
        strcat(gay,sss);
        strcat(gay,".txt");
        FILE* re=fopen(gay,"w+");
        fprintf(re,"%s\n",tag_name);
        fseek(re,0,2);
        fprintf(re,"%d-%02d-%02d %02d:%02d:%02d\n", time.tm_year + 1900, time.tm_mon + 1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
        fseek(re,0,2);
        fprintf(re,"%s",commit_id);
        fseek(re,0,2);
        fprintf(re,"%s\n",auth_name);
        fseek(re,0,2);
        fprintf(re,"%s\n",email);
        fseek(re,0,2);
        fprintf(re,"%s\n",message);
    }
    else{

        printf("don't you dare make a tag with the same name\n");
    }

}






