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
    if(GetCurrentDirectory(256,current_dir)==NULL){
        return 1;
    }
    int is_there_a_shiz_dir=check_shiz_local_dir_rec(current_dir);
    
    //
    if (argc==2)
    {
        if (strcmp(argv[1],"init")==0)
        {
            
            if (is_there_a_shiz_dir==1)
            {
                perror("there is a .shiz directory in one of the parent directories\n");
            }
            else if(is_there_a_shiz_dir==0)
            {
                create_local_shiz_dir(".\\.shiz");
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
    }
    
    
    
    
    
    
    return 0;
}