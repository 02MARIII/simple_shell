/**
 * _getenv - Get the value of an environment variable.
 * @vr: The name of the environment variable.
 *
 * Return:
 *  - On success, returns a pointer to the value of the environment variable.
 *  - If the environment variable is not found, returns NULL.
 */
char *_getenv(char *vr)
{
	char *temp, *env;
	char *name, *val;
	int i = 0;

	while (environ[i])
	{
		temp = _strdup(environ[i]);
		name = strtok(temp, "=");
		if (_strcmp(name, vr) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(temp);
			return (env);
		}
		free(temp);
		temp = NULL;
		i++;
	}
	return (NULL);
}

