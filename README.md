# Observer
> A pure C implementation of the observer pattern

## Quick start

### Model
```c
#include <subject.h>

struct model_t {
  subject_t *subject;
};

model_t *model_new(void) {
  model_t *model = malloc(sizeof(model_t));

  model->subject = subject_new();

  return model;
}

void model_free(model_t *model) {
  if (model != NULL) {
    subject_delete(model->subject);

    free(model);
  }
}

void model_attach(model_t *model, const observer_t *observer) {
  subject_attach(model->subject, observer);
}

void model_detach(model_t *model, const observer_t *observer) {
  subject_detach(model->subject, observer);
}
```

#### Controller
```c
#include <observer.h>

struct controller_t {
  const model_t *model;

  observer_t *observer;
};

static void controller_update(const void *context, int argc, const void *argv[]) {
  controller_t *controller = (controller_t *) context;
  const model_t *model = (const model_t *) argv[0];
}

controller_t *controller_new(const model_t *model, const view_t *view) {
  controller_t *controller = malloc(sizeof(controller_t));

  controller->model = model;
  controller->observer = observer_new(controller, controller_update);

  return controller;
}

void controller_free(controller_t *controller) {
  if (controller != NULL) {
    observer_delete(controller->observer);

    free(controller);
  }
}

const observer_t *controller_get_observer(const controller_t *controller) {
  return controller->observer;
}
```
