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
    char* stage_dir=(char*) calloc(256,1);
    char* storage_dir=(char*) calloc(256,1);
    char* shiz_dir=(char*) calloc(256,1);
    char* current_branch_dir=(char*) calloc(256,1);
    char* user_name_file_loc=(char*) calloc(256,1);
    char* previous_branch=(char*) calloc(256,1);
    char* user_name=(char*) calloc(256,1);
    FILE* current_branch_file;
    FILE* user_name_file;
    char* current_branch=(char*) calloc(256,1);
    if (is_there_a_shiz_dir!=-1)
    {
        
        find_shiz_local_dir(shiz_dir,current_dir,check_shiz_local_dir_rec(current_dir,0));
        find_shiz_local_dir(stage_dir,current_dir,check_shiz_local_dir_rec(current_dir,0));
        find_shiz_local_dir(storage_dir,current_dir,check_shiz_local_dir_rec(current_dir,0));
        find_shiz_local_dir(current_branch_dir,current_dir,check_shiz_local_dir_rec(current_dir,0));
        find_shiz_local_dir(user_name_file_loc,current_dir,check_shiz_local_dir_rec(current_dir,0));
        strcat(user_name_file_loc,"\\.shiz\\name.txt");
        strcat(stage_dir,"\\.shiz\\stage");
        strcat(storage_dir,"\\.shiz\\storage");
        strcat(current_branch_dir,".\\.shiz\\storage\\current_branch.txt");
        user_name_file=fopen(user_name_file_loc,"r");
        current_branch_file=fopen(current_branch_dir,"r");
        fscanf(user_name_file,"name: %s\n",user_name);
        fscanf(current_branch_file,"%s",current_branch);
        fclose(current_branch_file);
    }
    
    
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
                create_local_shiz_dir(".\\.shiz\\storage");
                FILE* file22=fopen(".\\.shiz\\storage\\current_branch.txt","w+");
                strcpy(previous_branch,"NULL");
                fprintf(file22,"main_0");
                fclose(file22);
            }
            else
            {
                printf("there is a .shiz directory in one of the parent directories(depth:%d)\n",is_there_a_shiz_dir);
            }
            
        }
        else if (strcmp(argv[1],"show-content")==0)
        {
            char* names[100];
            for (int i = 0; i < 100; i++)
            {
                names[i]=(char*) calloc(256,1);
            }
            all_file_dirs(current_dir,names);
            for (int i = 0; i < 100; i++)
            {
                if (strcmp(names[i],"")!=0)
                {
                    printf("%s\n",names[i]);
                }
                
                
            }
            

            
            
        }
        else if (strcmp(argv[1],"show-rec-content")==0)
        {
            char* list=(char*) calloc(10000,1);
            
            
            listFilesRecursively(current_dir,list);
            printf("%s\n",list);
                

            
            
        }
        else if (strcmp(argv[1],"show-stage-content")==0)
        {
            char* list=(char*) calloc(10000,1);
            
            
            listFilesRecursively_stage(stage_dir,list);
            printf("%s\n",list);
                

            
            
        }
        else if (strcmp(argv[1],"status")==0)
        {
           status(current_dir,stage_dir,shiz_dir);
        }
        else if (strcmp(argv[1],"empty")==0)
        {
            empty_dir(current_dir);
            
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
        else if (strcmp(argv[1],"turkiye")==0&&strcmp(argv[2],"forever")==0)
        {
            printf("join the turkish legion against the tyrany of greeke menace\n");
            printf("https://t.me/turkiye_forever\n");
        }
        else if (strcmp(argv[1],"add")==0&&strcmp(argv[2],"all")!=0)
        {
            send_to_storage(strlen(shiz_dir),strlen(current_dir),argv[2],stage_dir,current_dir);
        }
        else if (strcmp(argv[1],"add")==0&&strcmp(argv[2],"all")==0)
        {
            send_to_storage(strlen(shiz_dir),strlen(current_dir),current_dir,stage_dir,current_dir);
            
        }
        else if (strcmp(argv[1],"add")==0&&strcmp(argv[2],"-redo")==0)
        {
            //to be imlemented
            redo_stage(stage_dir,shiz_dir);
        }
        else if (strcmp(argv[1],"rest")==0)
        {
            unstage(stage_dir,shiz_dir,argv[2],current_dir);
        }
        else if (strcmp(argv[1],"check-stage")==0)
        {
            printf("out code is:%d\n",check_if_staged_reverse(argv[2],stage_dir,shiz_dir));
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
        else if (strcmp(argv[1],"add")==0&&strcmp(argv[2],"-f")==0)
        {
            int num=decipher(strlen(argv[3])+1,argv[3]);
            check_staged_rec(current_dir,stage_dir,shiz_dir,num);
        }
        else if (strcmp(argv[1],"commit")==0&&strcmp(argv[2],"-m")==0)
        {
            strcpy(previous_branch,current_branch);
            commit(previous_branch,number_files(stage_dir),user_name,current_branch,argv[3],stage_dir,storage_dir,shiz_dir);
            FILE* temp33=fopen(current_branch_dir,"r+");
            fprintf(temp33,"%s",current_branch);
            fclose(temp33);
            empty_dir(stage_dir);
            empty_dir(stage_dir);
            empty_dir(stage_dir);
            empty_dir(stage_dir);
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
                    send_to_storage(strlen(shiz_dir),strlen(current_dir),argv[i],stage_dir,current_dir);
                }
                
                
            }
            
        }
        else if (strcmp(argv[1],"rest")==0&&strcmp(argv[2],"-f")==0){
            for (int i = 3; i < argc; i++)
            {
                unstage(stage_dir,shiz_dir,argv[i],current_dir);
            }
            

        }

    }
    
    
    

    printf("\n\n\n\n\n\n\n");
    printf("storage dir:%s\n\n",storage_dir);
    printf("stage dir:%s\n\n",stage_dir);
    printf("current branch:%s\n",current_branch);
    printf("number of args:\n%d\n\n",argc);
    printf("current dir:\n%s\n\n",current_dir);
    printf("args:\n");
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n",argv[i]);
    }
    printf("\n\n\n");
    
    
    return 0;
}