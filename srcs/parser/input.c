#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "nn.h"

#define MAX_CHAR_LINE 200
# define NUMS	"-0123456789"

int	extract_num(char *str, int *number)
{
	int spn;

	spn = strcspn(str, NUMS);
	*number = atoi(str + spn);
	return spn + strspn(str + spn, NUMS);
}

void parse_input(char *filename, TDataSet *training_data)
{
    FILE *file;
    char line[MAX_CHAR_LINE] = {0};
    char *res;

    file = fopen(filename, "r");


    fgets(line, MAX_CHAR_LINE, file);
    extract_num(line, &training_data->set_count);

    int offset = 0;
    fgets(line, MAX_CHAR_LINE, file);
    offset += extract_num(line, &training_data->i_count);
    extract_num(line + offset, &training_data->o_count);

    training_data->sets = calloc(sizeof *training_data->sets, training_data->set_count);

    printf("Total %d Inputs: %d outputs %d \n",training_data->set_count, training_data->i_count, training_data->o_count);

    int x = 0;
    TData *set;
    do
    {
        offset = 0;
        res = fgets(line, MAX_CHAR_LINE, file);
        set = &training_data->sets[x];
        set->input = calloc(sizeof *(training_data->sets[x].output), training_data->i_count);
        set->output = calloc(sizeof *(training_data->sets[x].input), training_data->o_count);


        for (int i = 0; i < training_data->i_count; ++i)
        {
            offset += extract_num(line + offset, &set->input[i]);
            printf("Data in %d ", set->input[i]);
        }
        for (int i = 0; i < training_data->o_count; ++i)
        {
            offset += extract_num(line + offset, &set->output[i]);
            printf("Data out %d ", set->output[i]);
        }
        printf("End line %d \n", x);
        ++x;
    } while (x < training_data->set_count && res != NULL);

}
