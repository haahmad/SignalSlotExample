SignalSlotExample
=================

Use Qt signals and slots in native extensions for BB10 HTML5 apps

- Triggers NotifyEvent to JNEXT context when receiving the activeChanged signal from bb::device:Led
- Assumes you know how to generate moc files

```
moc -o moc_class.cpp class.hpp
```

- Import existing project into workspace, build
- Copy built .so file into a JavaScript extension project, (I haven't written a JavaScript part to this extension yet)
