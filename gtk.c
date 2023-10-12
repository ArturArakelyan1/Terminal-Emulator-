#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <unistd.h>
#include <libgen.h>
#include <stdlib.h>
​
static GtkTextBuffer *text_buffer;
static char *wd;
​
void add_text(const char *data) {
    // Append the entered text to the text view as a new block
    GtkTextIter iter;
    gtk_text_buffer_get_end_iter(text_buffer, &iter);
    gtk_text_buffer_insert(text_buffer, &iter, data, -1);
}
​
static char *execute_cmd(const char *command) {
    char input[128];
    char buffer[128];
    sprintf(input, "echo \"%s\" | shell/hsh", command);
​
    FILE *pipe = popen(input, "r");
​
    if (pipe == NULL) {
        perror("popen");
        return NULL;
    }
​
    char *result = NULL;
    size_t result_size = 0;
​
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        // Append the output to the result
        size_t buffer_len = strlen(buffer);
        result = realloc(result, result_size + buffer_len + 1);
        if (result) {
            strcpy(result + result_size, buffer);
            result_size += buffer_len;
        }
    }
​
    int status = pclose(pipe);
    if (status == -1) {
        perror("pclose");
        free(result);
        return NULL;
    }
​
    char tmp[128];
    getcwd(tmp, sizeof(tmp));
    char *dir_name = basename(tmp);
    free(wd);
    wd = strdup(dir_name);
    g_print(wd);
​
    return result;
}
​
static gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer data, char* wd) {
    if (event->keyval == GDK_Return) {
        const gchar *text = gtk_entry_get_text(GTK_ENTRY(data)); 
        char* res = execute_cmd(text);
        if (res) {
            add_text(res);
            free(res); 
        }
        return TRUE; 
    }
​
    return FALSE; 
}
​
int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *table;
    GtkWidget *label;
    GtkWidget *entry;
​
    char tmp[128];
    getcwd(tmp, sizeof(tmp));
    wd = strdup(basename(tmp)); 
    gtk_init(&argc, &argv);
​
    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Terminator");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
​
    // Create a table to hold the label and input field
    table = gtk_table_new(1, 2, FALSE); // 1 row, 2 columns, no spacing
    gtk_container_add(GTK_CONTAINER(window), table);
​
    // Create a label
    label = gtk_label_new(wd);
    // Set alignment to left
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
    gtk_table_attach(table, label, 0, 1, 0, 1, GTK_FILL, 0, 0, 0);
​
    // Create the input field
    entry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    gtk_table_attach(table, entry, 1, 2, 0, 1, GTK_EXPAND | GTK_FILL, 0, 0, 0);
    // Create a text view to display the results
    GtkWidget *text_view = gtk_text_view_new();
    text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
​
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD_CHAR);
​
    // Add the text view to the table
    gtk_table_attach(table, text_view, 0, 2, 1, 2, GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
​
    g_signal_connect(window, "key-press-event", G_CALLBACK(on_key_press), entry);
    // Show all widgets
    gtk_widget_show_all(window);
​
    gtk_main();
    return 0;
}
