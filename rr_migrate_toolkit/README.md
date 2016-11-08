# RR Migrate Toolkit
Migration of files, taxonomy and content types from Drupal 6 to Drupal 7.

## (rr_migrate_toolkit)

### Drush Commands:

List Migration related commands in Drush: `drush help --filter="migrate"`

Register the migration: `drush mreg <migration_name>` (i.e. `drush mreg ToolkitFiles`)

View the current status: `drush ms <migration_name>` (i.e. `drush ms ToolkitFiles`)

View messages such as error messages: `drush mmsg <migration_name>` (i.e. `drush mmsg ToolkitFiles`)

Run the migration: `drush mi <migration_name>` (i.e. `drush mi ToolkitFiles`)

Run the migration but limited: `drush mi <migration_name> --limit="10 items"` (i.e. `drush mi ToolkitFiles --limit="10 items"`)
