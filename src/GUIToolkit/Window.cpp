/*
 * Every window must have the following:
 * 1. Minimize, Maximize, Close, and/or Help button.
 * 2. A Frame (or no frame).
 * These controls will make up the Non-Client Area.
 * The Client Area must be a frame (panel) control that must:
 * Allow adding controls based upon the x, y, width and height
 * of the frame (panel) control in the window. This *should*
 * create a gui like system similar to linux, mac and windows.
 *
 * And yes why not make my own gui toolkit for my OS.
 *
 * Also each window must create it's own handle that can then be
 * possibly tracked by the OS and discarded (with the controls)
 * When the window is closed or something.
 */
