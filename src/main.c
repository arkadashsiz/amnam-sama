#include <functions.h>


#define a
#ifdef _DBG
int main(){
    int argc=2;
    char* argv[2]={"shiz","init"};


#else
int main(int argc,char *argv[]){


#endif
    int argcv=argc;
    char* argvv[argc];
    for (int i = 0; i < argc; i++)
    {
        argvv[i]=(char*) calloc(256,1);
        strcpy(argvv[i],argv[i]);
    }
    
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
    char* email_file_loc=(char*) calloc(256,1);
    char* previous_branch=(char*) calloc(256,1);
    char* user_name=(char*) calloc(256,1);
    char* email=(char*) calloc(256,1);
    char* previous_file_location=(char*) calloc(256,1);
    FILE* current_branch_file;
    FILE* user_name_file;
    FILE* previous_branch_file;
    FILE* email_file;
    char* current_branch=(char*) calloc(256,1);
    if (is_there_a_shiz_dir!=-1)
    {
        
        find_shiz_local_dir(shiz_dir,current_dir,check_shiz_local_dir_rec(current_dir,0));
        find_shiz_local_dir(stage_dir,current_dir,check_shiz_local_dir_rec(current_dir,0));
        find_shiz_local_dir(storage_dir,current_dir,check_shiz_local_dir_rec(current_dir,0));
        find_shiz_local_dir(current_branch_dir,current_dir,check_shiz_local_dir_rec(current_dir,0));
        find_shiz_local_dir(user_name_file_loc,current_dir,check_shiz_local_dir_rec(current_dir,0));
        find_shiz_local_dir(previous_file_location,current_dir,check_shiz_local_dir_rec(current_dir,0));
        strcat(previous_file_location,".\\.shiz\\storage\\previous_branch.txt");
        strcat(user_name_file_loc,"\\.shiz\\name.txt");
        strcat(email_file_loc,"\\.shiz\\email.txt");
        strcat(stage_dir,"\\.shiz\\stage");
        strcat(storage_dir,"\\.shiz\\storage");
        strcat(current_branch_dir,".\\.shiz\\storage\\current_branch.txt");
        previous_branch_file=fopen(previous_file_location,"r");
        user_name_file=fopen(user_name_file_loc,"r");
        email_file=fopen(email_file_loc,"r");
        if (user_name_file==NULL)
        {
            user_name_file=fopen("C:\\shiz\\name.txt","r");
        }
        if (email_file==NULL)
        {
            email_file=fopen("C:\\shiz\\email.txt","r");
        }
        
        current_branch_file=fopen(current_branch_dir,"r");
        fscanf(previous_branch_file,"%s",previous_branch);
        fscanf(user_name_file,"name: %s\n",user_name);
        fscanf(email_file,"email: %s\n",email);
        fscanf(current_branch_file,"%s",current_branch);
        fclose(current_branch_file);
        fclose(previous_branch_file);
        fclose(user_name_file);
        //////////////////////////////////
        
    }
    
    
    if (argc==1)
    {
        printf("you stupid little shit\n");
    }
    
    else if (argc==2)
    {
        if (strcmp(argv[1],"init")==0)
        {
            if(is_there_a_shiz_dir==-1)
            {
                create_local_shiz_dir(".\\.shiz");
                create_local_shiz_dir(".\\.shiz\\stage");
                create_local_shiz_dir(".\\.shiz\\storage");
                create_local_shiz_dir(".\\.shiz\\storage\\tag");
                FILE* filenum=fopen(".\\.shiz\\storage\\tag\\num.txt","w+");
                FILE* file123=fopen(".\\.shiz\\storage\\all_branch.txt","w+");
                FILE* file22=fopen(".\\.shiz\\storage\\current_branch.txt","w+");
                FILE* init_loove=fopen(".\\.shiz\\storage\\head_branch.txt","w+");
                FILE* prev_br=fopen(".\\.shiz\\storage\\previous_branch.txt","w+");
                fprintf(filenum,"0");
                fprintf(init_loove,"main_0");
                fprintf(prev_br,"%s","NULL");
                fprintf(file123,"main\n");
                fprintf(file22,"main_0");
                fclose(prev_br);
                fclose(filenum);
                fclose(init_loove);
                fclose(file22);
                fclose(file123);
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
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
           status(current_dir,stage_dir,shiz_dir);
            }
        }
        else if (strcmp(argv[1],"empty")==0)
        {
            empty_dir(current_dir);
            
        }
        else if (strcmp(argv[1],"branch")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            show_all_branches(storage_dir);
            }
        }
        else if (strcmp(argv[1],"log")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            logs(0,storage_dir);
            }
        }
        else if (strcmp(argv[1],"tag")==0)
        {
            char* qwwqq=(char*) calloc(256,1);
            strcpy(qwwqq,storage_dir);
            strcat(qwwqq,"\\tag");
            char* alsw=(char*) calloc(10000,1);
            char* all_tags[20];
            for (int i = 0; i < 20; i++)
            {
                all_tags[20]=(char*) calloc(256,1);
            }
            listFilesRecursively(qwwqq,alsw);
            turn_str_to_list(alsw,all_tags);
            int count=0;
            while (strcmp(all_tags[count],"")!=0)
            {
                count++;
            }
            char* num_loc_list_69=(char*) calloc(256,1);
            strcpy(num_loc_list_69,storage_dir);
            strcat(num_loc_list_69,"\\tag\\num.txt");
            for (int i = 0; i < count; i++)
            {
                if (strcmp(num_loc_list_69,all_tags[i])!=0)
                {
                    FILE* fofoisbad=fopen(all_tags[i],"r");
                    char* text=(char*) calloc(300,1);
                    for (int j = 0; j < 300; j++)
                    {
                        fseek(fofoisbad,j,0);
                        fscanf(fofoisbad,"%c",text+j);
                    }
                    for (int j = 0; j < 300; j++)
                    {
                        printf("%c",*(text+j));
                    }
                    fclose(fofoisbad);
                }
                printf("-----------------\n");
            }
            
        }
    
    }
    else if (argc==3)
    {
        if (strcmp(argv[1],"hash")==0)
        {
            char* hash_code=(char*) calloc(16,1);
            FILE* file=fopen(argv[2],"r+");
            if (file==NULL)
            {
                printf("file does not exist\n");
            }
            else{
                hash_file(file,hash_code);
                for (int i = 0; i < 16; i++)
                {
                    printf("%c",*(hash_code+i));
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
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            send_to_storage(strlen(shiz_dir),strlen(current_dir),argv[2],stage_dir,current_dir);
            }
        }
        else if (strcmp(argv[1],"add")==0&&strcmp(argv[2],"all")==0)
        {   if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            send_to_storage(strlen(shiz_dir),strlen(current_dir),current_dir,stage_dir,current_dir);
            }
        }
        else if (strcmp(argv[1],"add")==0&&strcmp(argv[2],"-redo")==0)
        {
            //to be imlemented
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            redo_stage(stage_dir,shiz_dir);
            }
        }
        else if (strcmp(argv[1],"rest")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            unstage(stage_dir,shiz_dir,argv[2],current_dir);
            }
        }
        else if (strcmp(argv[1],"rest")==0&&strcmp(argv[2],"-undo")==0)
        {
            //busssss
        }
        else if (strcmp(argv[1],"check-stage")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            printf("out code is:%d\n",check_if_staged_reverse(argv[2],stage_dir,shiz_dir));
            }
        }
        else if (strcmp(argv[1],"branch")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            branch(argv[2],current_branch,previous_branch,storage_dir);
            }
        }
        else if (strcmp(argv[1],"checkout")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            check_out(argv[2],storage_dir,shiz_dir);\
            }
        }
        else if (strcmp(argv[1],"checkout")==0&&strcmp(argv[2],"HEAD")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            char* head=(char*) calloc(256,1);
            char* head_loc=(char*) calloc(256,1);
            strcpy(head_loc,storage_dir);
            strcat(head_loc,"\\head_branch.txt");
            FILE* tombussy=fopen(head_loc,"r");
            fscanf(tombussy,"%s",head);
            fclose(tombussy);
            int tempwasadream=0;
            while (*(head+tempwasadream)!='_')
            {
                tempwasadream++;
            }
            char* exit=(char*) calloc(256,1);
            copy(exit,head,tempwasadream);
            
            check_out(exit,storage_dir,shiz_dir);
            }
        }
        else if (strcmp(argv[1],"revert")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            char* pos_of_wanted_commit_to_revert=(char*) calloc(256,1);
            revert_with_out_commit(pos_of_wanted_commit_to_revert,argv[2],storage_dir,shiz_dir);
            
            send_rec_to_shiz(strlen(pos_of_wanted_commit_to_revert),pos_of_wanted_commit_to_revert,shiz_dir);
            send_to_storage(strlen(shiz_dir),strlen(shiz_dir),shiz_dir,stage_dir,current_dir);
            
            
            
            char w[24]="this is reverted commit";
            commit(previous_branch,number_files(stage_dir),user_name,current_branch,w,stage_dir,storage_dir,shiz_dir);
            FILE* egg=fopen(previous_file_location,"r+");
            fprintf(egg,"%s",previous_branch);
            FILE* temp33=fopen(current_branch_dir,"r+");
            fprintf(temp33,"%s",current_branch);
            fclose(temp33);
            fclose(egg);
            empty_dir(stage_dir);
            empty_dir(stage_dir);
            empty_dir(stage_dir);
            empty_dir(stage_dir);
            }

        }
        else if (strcmp(argv[1],"clear")==0&&strcmp(argv[2],"shiz")==0)
        {
            empty_shiz_dir(shiz_dir);
            empty_shiz_dir(shiz_dir);
        }
        else if (strcmp(argv[1],"dis")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            printf("dis is:%d\n",dis_to_base(argv[2],storage_dir));
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
            }
        }
        else if (strcmp(argv[1],"add")==0&&strcmp(argv[2],"-f")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            int num=decipher(strlen(argv[3])+1,argv[3]);
            check_staged_rec(current_dir,stage_dir,shiz_dir,num);
            }
        }
        else if (strcmp(argv[1],"commit")==0&&strcmp(argv[2],"-m")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            commit(previous_branch,number_files(stage_dir),user_name,current_branch,argv[3],stage_dir,storage_dir,shiz_dir);
            FILE* egg=fopen(previous_file_location,"r+");
            fprintf(egg,"%s",previous_branch);
            FILE* temp33=fopen(current_branch_dir,"r+");
            fprintf(temp33,"%s",current_branch);
            fclose(temp33);
            fclose(egg);
            empty_dir(stage_dir);
            empty_dir(stage_dir);
            empty_dir(stage_dir);
            empty_dir(stage_dir);
            }
        }
        else if (strcmp("remove",argv[1])==0&&strcmp("-s",argv[2])==0){
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            char* loc=(char*) calloc(256,1);
            strcpy(loc,shiz_dir);
            strcat(loc,"\\.shiz\\shortcut.txt");
            FILE* fer=fopen(loc,"w+");
            fclose(fer);
            }
        }
        else if (strcmp(argv[1],"log")==0&&strcmp(argv[2],"-n")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            logs(decipher(strlen(argv[3]),argv[3]),storage_dir);
            }
        }
        else if (strcmp(argv[1],"log")==0&&strcmp(argv[2],"-branch")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            logs_branch(argv[3],storage_dir);
            }
        }
        else if (strcmp(argv[1],"log")==0&&strcmp(argv[2],"-author")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            logs_author(argv[3],storage_dir);
            }
        }
        else if (strcmp(argv[1],"log")==0&&strcmp(argv[2],"-before")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            logs_time(1,argv[3],storage_dir);
            }
        }
        else if (strcmp(argv[1],"log")==0&&strcmp(argv[2],"-since")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            logs_time(0,argv[3],storage_dir);
            }
        }
        else if (strcmp(argv[1],"log")==0&&strcmp(argv[2],"-search")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            logs_word(argv[3],storage_dir);
            }
        }
        else if (strcmp(argv[1],"checkout")==0&&strcmp(argv[1],"HEAD")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            char* orgy_loc=(char*) calloc(256,1);
            n_before_head(orgy_loc,decipher(strlen(argv[3]),argv[3]),storage_dir);
            check_out(orgy_loc,storage_dir,shiz_dir);
            }
        }
        else if (strcmp(argv[1],"revert")==0&&strcmp(argv[2],"-n")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            char* pos_of_wanted_commit_to_revert=(char*) calloc(256,1);
            revert_with_out_commit(pos_of_wanted_commit_to_revert,argv[3],storage_dir,shiz_dir);
            send_rec_to_shiz(strlen(pos_of_wanted_commit_to_revert),pos_of_wanted_commit_to_revert,shiz_dir);
            send_to_storage(strlen(shiz_dir),strlen(shiz_dir),shiz_dir,stage_dir,current_dir);
            }


        }
        else if (strcmp(argv[1],"tag")==0&&strcmp(argv[2],"show")==0)
        {
            char* qwwqq=(char*) calloc(256,1);
            strcpy(qwwqq,storage_dir);
            strcat(qwwqq,"\\tag");
            char* alsw=(char*) calloc(10000,1);
            char* all_tags[20];
            for (int i = 0; i < 20; i++)
            {
                all_tags[20]=(char*) calloc(256,1);
            }
            listFilesRecursively(qwwqq,alsw);
            turn_str_to_list(alsw,all_tags);
            int count=0;
            while (strcmp(all_tags[count],"")!=0)
            {
                count++;
            }
            char* num_loc_list_69=(char*) calloc(256,1);
            strcpy(num_loc_list_69,storage_dir);
            strcat(num_loc_list_69,"\\tag\\num.txt");
            for (int i = 0; i < count; i++)
            {
                if (strcmp(num_loc_list_69,all_tags[i])!=0)
                {
                    FILE* fofoisbad=fopen(all_tags[i],"r");
                    char* name=(char*) calloc(256,1);
                    if (strcmp(name,argv[3])==0)
                    {
                        char* text=(char*) calloc(300,1);
                        for (int j = 0; j < 300; j++)
                        {
                            fseek(fofoisbad,j,0);
                            fscanf(fofoisbad,"%c",text+j);
                        }
                        for (int j = 0; j < 300; j++)
                        {
                            printf("%c",*(text+j));
                        }
                    }
                    fclose(fofoisbad);
                    
                }
                printf("-----------------\n");
            }
            
        }
        else if (strcmp("tag",argv[1])==0&&strcmp("-a",argv[2])==0)
        {
            char* coste=(char*) calloc(256,1);
            strcpy(coste,storage_dir);
            strcat(coste,"previous_branch.txt");
            FILE* loste=fopen(coste,"r");
            char* hash33=(char*) calloc(16,1);
            fseek(loste,0,2);
            int hy=0;
            char cum;
            int loz=ftell(loste);
            while (hy<=4)
            {
                
                fseek(loste,loz,0);
                fscanf(loste,"%c",&cum);
                if (cum=='\n')
                {
                    hy++;
                }
                loz--;
            }            
            
            
            for (int vv = 0; vv < 100; vv++)
            {
                fseek(loste,loz+2,0);
                fscanf(loste,"%c",hash33+vv);
                loz++;
                if (*(hash33+vv)=='\n')
                {
                    break;
                }
                
            }
            tag(storage_dir,"none",argv[3],hash33,user_name,email);

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
        else if (strcmp("diff",argv[1])==0&&strcmp("-f",argv[2])==0)
        {
            diff(argv[3],argv[4]);
        }
        else if (strcmp("diff",argv[1])==0&&strcmp("-c",argv[2])==0)
        {
            
            diff_commits(argv[3],argv[4],storage_dir);
        }
        else if (strcmp("merge",argv[1])==0&&strcmp("-b",argv[2])==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            merge(argv[3],argv[4],storage_dir,stage_dir,shiz_dir);
            }
        }
    }
    else if (argc==6)
    {
        if (strcmp("set",argv[1])==0&&strcmp("-m",argv[2])==0&&strcmp("-s",argv[4])==0)
        {
            char* loc=(char*) calloc(256,1);
            strcpy(loc,shiz_dir);
            strcat(loc,"\\.shiz\\shortcut.txt");
            FILE* fer=fopen(loc,"w+");
            fprintf(fer,"%s:%s\n",argv[5],argv[3]);
            fclose(fer);

        }
        else if (strcmp("replace",argv[1])==0&&strcmp("-m",argv[2])==0&&strcmp("-s",argv[4])==0)
        {
            char* loc=(char*) calloc(256,1);
            strcpy(loc,shiz_dir);
            strcat(loc,"\\.shiz\\shortcut.txt");
            FILE* fer=fopen(loc,"w+");
            fprintf(fer,"%s:%s\n",argv[5],argv[3]);
            fclose(fer);

        }
        else if (strcmp("tag",argv[1])==0&&strcmp("-a",argv[2])==0&&strcmp("-c",argv[4])==0)
        {
            char* coste=(char*) calloc(256,1);
            strcpy(coste,storage_dir);
            strcat(coste,"previous_branch.txt");
            FILE* loste=fopen(coste,"r");
            
            
            tag(storage_dir,"none",argv[3],argv[5],user_name,email);

        }
        else if (strcmp("tag",argv[1])==0&&strcmp("-a",argv[2])==0&&strcmp("-m",argv[4])==0)
        {
            char* coste=(char*) calloc(256,1);
            strcpy(coste,storage_dir);
            strcat(coste,"previous_branch.txt");
            FILE* loste=fopen(coste,"r");
            char* hash33=(char*) calloc(16,1);
            fseek(loste,0,2);
            int hy=0;
            char cum;
            int loz=ftell(loste);
            while (hy<=4)
            {
                
                fseek(loste,loz,0);
                fscanf(loste,"%c",&cum);
                if (cum=='\n')
                {
                    hy++;
                }
                loz--;
            }            
            
            
            for (int vv = 0; vv < 100; vv++)
            {
                fseek(loste,loz+2,0);
                fscanf(loste,"%c",hash33+vv);
                loz++;
                if (*(hash33+vv)=='\n')
                {
                    break;
                }
                
            }
            tag(storage_dir,argv[5],argv[3],hash33,user_name,email);

        }

    }
    else if (argc==8)
    {
        if (strcmp("tag",argv[1])==0&&strcmp("-a",argv[2])==0&&strcmp("-m",argv[4])==0&&strcmp("-c",argv[6])==0)
        {
            char* coste=(char*) calloc(256,1);
            strcpy(coste,storage_dir);
            strcat(coste,"previous_branch.txt");
            FILE* loste=fopen(coste,"r");
            
            tag(storage_dir,argv[5],argv[3],argv[7],user_name,email);

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
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            for (int i = 3; i < argc; i++)
            {
                unstage(stage_dir,shiz_dir,argv[i],current_dir);
            }
            }

        }
        else if (strcmp(argv[1],"log")==0&&strcmp(argv[2],"-search")==0)
        {
            if (is_there_a_shiz_dir==-1)
            {
                printf(".shiz file does not exist\n");
            }
            else{
            for (int i = 3; i < argc; i++)
            {
                logs_word(argv[i],storage_dir);
            }
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