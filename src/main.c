#include <functions.h>


#define a
#ifdef _DBG
int main(){
    int argc=2;
    char* argv[2]={"shiz","init"};


#else
int main(int argc,char *argv[]){


#endif
    check_global_dir();
    //current working diractory
    char* current_dir=(char*)calloc(256,1);
    GetCurrentDirectory(256,current_dir);
    
    int is_there_a_shiz_dir=check_shiz_local_dir_rec(current_dir,0);
    //
    if (argc==1)
    {
        printf("you stupid little shit\n");
    }
    
    if (argc==2)
    {
        if (strcmp(argv[1],"init")==0)
        {
            if(is_there_a_shiz_dir==-1)
            {
                create_local_shiz_dir(".\\.shiz");
                create_local_shiz_dir(".\\.shiz\\stage");
                create_local_shiz_dir(".\\.shiz\\depository");
            }
            else
            {
                printf("there is a .shiz directory in one of the parent directories(depth:%d)\n",is_there_a_shiz_dir);
            }
            
        }
        
    }
    else if (argc==3)
    {
        if (strcmp(argv[1],"hash")==0)
        {
            unsigned char* hash_code=(unsigned char*) calloc(16,1);
            FILE* file=fopen(argv[2],"r+");
            if (file==NULL)
            {
                printf("file does not exist\n");
            }
            else{
                hash_file(file,hash_code);
                for (int i = 0; i < 16; i++)
                {
                    printf("%x",*(hash_code+i));
                }
                printf("\n");
                
            }
        }
        
    }
    
    else if (argc==4)
    {
        if (strcmp(argv[1],"config")==0&&strcmp(argv[2],"user.name")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
                config_name(argc,argv,current_dir);
            }
            
        }
        else if (strcmp("config",argv[1])==0&&strcmp("user.email",argv[2])==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
                config_email(argc,argv,current_dir);
            }
        }
        else if (strcmp("config",argv[1])==0&&comp_word(argv[2],"alias.",6)==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
                config_alias(argc,argv,current_dir);
                //currently it does not return an error for non functioning commands
            }
        }
    }
    
    else if (argc==5)
    {
        if (strcmp(argv[1],"config")==0&&strcmp(argv[2],"-global")==0&&strcmp(argv[3],"user.name")==0)
        {
            config_glob_name(argc,argv);
        }
        else if (strcmp("config",argv[1])==0&&strcmp("-global",argv[2])==0&&strcmp("user.email",argv[3])==0)
        {
            config_glob_email(argc,argv);
        }
        else if (strcmp("config",argv[1])==0&&strcmp("-global",argv[2])==0&&comp_word("alias.",argv[3],6)==0)
        {
            config_glob_alias(argc,argv);
            //currently it does not return an error for non functioning commands
        }
    }
    
    if (argc>1)
    {
        if (strcmp(argv[1],"add")==0&&strcmp(argv[2],"-f")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
                for (int i = 3; i < argc; i++)
                {
                    printf("your out put is %d\n", send_file_to_stage(current_dir,argv[i]));
                }
                
                
            }
            
        }
        else if (strcmp(argv[1],"add")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
                printf("your out put is %d\n", send_file_to_stage(current_dir,argv[2]));
            }
            
        }
    }
    
    
    
    printf("number of args:\n%d\n\n",argc);
    printf("current dir:\n%s\n\n",current_dir);
    printf("args:\n");
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n",argv[i]);
    }
    
    
    
    return 0;
}