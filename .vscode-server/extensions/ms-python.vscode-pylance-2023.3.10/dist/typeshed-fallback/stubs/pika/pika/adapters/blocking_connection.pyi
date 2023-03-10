from _typeshed import Incomplete
from collections.abc import Generator, Sequence
from typing import NamedTuple
from typing_extensions import Self

from ..connection import Parameters
from ..data import _ArgumentMapping
from ..exchange_type import ExchangeType
from ..spec import BasicProperties

LOGGER: Incomplete

class _CallbackResult:
    def __init__(self, value_class: Incomplete | None = ...) -> None: ...
    def reset(self) -> None: ...
    def __bool__(self) -> bool: ...
    __nonzero__: Incomplete
    def __enter__(self): ...
    def __exit__(self, *args, **kwargs) -> None: ...
    def is_ready(self): ...
    @property
    def ready(self): ...
    def signal_once(self, *_args, **_kwargs) -> None: ...
    def set_value_once(self, *args, **kwargs) -> None: ...
    def append_element(self, *args, **kwargs) -> None: ...
    @property
    def value(self): ...
    @property
    def elements(self): ...

class _IoloopTimerContext:
    def __init__(self, duration, connection) -> None: ...
    def __enter__(self): ...
    def __exit__(self, *_args, **_kwargs) -> None: ...
    def is_ready(self): ...

class _TimerEvt:
    timer_id: Incomplete
    def __init__(self, callback) -> None: ...
    def dispatch(self) -> None: ...

class _ConnectionBlockedUnblockedEvtBase:
    def __init__(self, callback, method_frame) -> None: ...
    def dispatch(self) -> None: ...

class _ConnectionBlockedEvt(_ConnectionBlockedUnblockedEvtBase): ...
class _ConnectionUnblockedEvt(_ConnectionBlockedUnblockedEvtBase): ...

class BlockingConnection:
    class _OnClosedArgs(NamedTuple):
        connection: Incomplete
        error: Incomplete

    class _OnChannelOpenedArgs(NamedTuple):
        channel: Incomplete
    def __init__(
        self, parameters: Parameters | Sequence[Parameters] | None = ..., _impl_class: Incomplete | None = ...
    ) -> None: ...
    def __enter__(self) -> Self: ...
    def __exit__(self, exc_type: object, value: object, traceback: object) -> None: ...
    def add_on_connection_blocked_callback(self, callback) -> None: ...
    def add_on_connection_unblocked_callback(self, callback) -> None: ...
    def call_later(self, delay, callback): ...
    def add_callback_threadsafe(self, callback) -> None: ...
    def remove_timeout(self, timeout_id) -> None: ...
    def update_secret(self, new_secret, reason) -> None: ...
    def close(self, reply_code: int = ..., reply_text: str = ...) -> None: ...
    def process_data_events(self, time_limit: int = ...): ...
    def sleep(self, duration: float) -> None: ...
    def channel(self, channel_number: int | None = ...) -> BlockingChannel: ...
    @property
    def is_closed(self) -> bool: ...
    @property
    def is_open(self) -> bool: ...
    @property
    def basic_nack_supported(self) -> bool: ...
    @property
    def consumer_cancel_notify_supported(self) -> bool: ...
    @property
    def exchange_exchange_bindings_supported(self) -> bool: ...
    @property
    def publisher_confirms_supported(self) -> bool: ...
    basic_nack = basic_nack_supported
    consumer_cancel_notify = consumer_cancel_notify_supported
    exchange_exchange_bindings = exchange_exchange_bindings_supported
    publisher_confirms = publisher_confirms_supported

class _ChannelPendingEvt: ...

class _ConsumerDeliveryEvt(_ChannelPendingEvt):
    method: Incomplete
    properties: Incomplete
    body: Incomplete
    def __init__(self, method, properties, body) -> None: ...

class _ConsumerCancellationEvt(_ChannelPendingEvt):
    method_frame: Incomplete
    def __init__(self, method_frame) -> None: ...
    @property
    def method(self): ...

class _ReturnedMessageEvt(_ChannelPendingEvt):
    callback: Incomplete
    channel: Incomplete
    method: Incomplete
    properties: Incomplete
    body: Incomplete
    def __init__(self, callback, channel, method, properties, body) -> None: ...
    def dispatch(self) -> None: ...

class ReturnedMessage:
    method: Incomplete
    properties: Incomplete
    body: Incomplete
    def __init__(self, method, properties, body) -> None: ...

class _ConsumerInfo:
    SETTING_UP: int
    ACTIVE: int
    TEARING_DOWN: int
    CANCELLED_BY_BROKER: int
    consumer_tag: Incomplete
    auto_ack: Incomplete
    on_message_callback: Incomplete
    alternate_event_sink: Incomplete
    state: Incomplete
    def __init__(
        self, consumer_tag, auto_ack, on_message_callback: Incomplete | None = ..., alternate_event_sink: Incomplete | None = ...
    ) -> None: ...
    @property
    def setting_up(self): ...
    @property
    def active(self): ...
    @property
    def tearing_down(self): ...
    @property
    def cancelled_by_broker(self): ...

class _QueueConsumerGeneratorInfo:
    params: Incomplete
    consumer_tag: Incomplete
    pending_events: Incomplete
    def __init__(self, params, consumer_tag) -> None: ...

class BlockingChannel:
    class _RxMessageArgs(NamedTuple):
        channel: Incomplete
        method: Incomplete
        properties: Incomplete
        body: Incomplete

    class _MethodFrameCallbackResultArgs(NamedTuple):
        method_frame: Incomplete

    class _OnMessageConfirmationReportArgs(NamedTuple):
        method_frame: Incomplete

    class _FlowOkCallbackResultArgs(NamedTuple):
        active: Incomplete
    def __init__(self, channel_impl, connection) -> None: ...
    def __int__(self) -> int: ...
    def __enter__(self): ...
    def __exit__(self, exc_type, value, traceback) -> None: ...
    @property
    def channel_number(self): ...
    @property
    def connection(self): ...
    @property
    def is_closed(self): ...
    @property
    def is_open(self): ...
    @property
    def consumer_tags(self): ...
    def close(self, reply_code: int = ..., reply_text: str = ...): ...
    def flow(self, active): ...
    def add_on_cancel_callback(self, callback) -> None: ...
    def add_on_return_callback(self, callback): ...
    def basic_consume(
        self,
        queue,
        on_message_callback,
        auto_ack: bool = ...,
        exclusive: bool = ...,
        consumer_tag: Incomplete | None = ...,
        arguments: Incomplete | None = ...,
    ): ...
    def basic_cancel(self, consumer_tag): ...
    def start_consuming(self) -> None: ...
    def stop_consuming(self, consumer_tag: Incomplete | None = ...) -> None: ...
    def consume(
        self,
        queue,
        auto_ack: bool = ...,
        exclusive: bool = ...,
        arguments: Incomplete | None = ...,
        inactivity_timeout: Incomplete | None = ...,
    ) -> Generator[Incomplete, None, None]: ...
    def get_waiting_message_count(self): ...
    def cancel(self): ...
    def basic_ack(self, delivery_tag: int = ..., multiple: bool = ...) -> None: ...
    def basic_nack(self, delivery_tag: int = ..., multiple: bool = ..., requeue: bool = ...) -> None: ...
    def basic_get(self, queue, auto_ack: bool = ...): ...
    def basic_publish(
        self, exchange: str, routing_key: str, body: str | bytes, properties: BasicProperties | None = ..., mandatory: bool = ...
    ) -> None: ...
    def basic_qos(self, prefetch_size: int = ..., prefetch_count: int = ..., global_qos: bool = ...) -> None: ...
    def basic_recover(self, requeue: bool = ...) -> None: ...
    def basic_reject(self, delivery_tag: int = ..., requeue: bool = ...) -> None: ...
    def confirm_delivery(self) -> None: ...
    def exchange_declare(
        self,
        exchange: str,
        exchange_type: ExchangeType | str = ...,
        passive: bool = ...,
        durable: bool = ...,
        auto_delete: bool = ...,
        internal: bool = ...,
        arguments: _ArgumentMapping | None = ...,
    ): ...
    def exchange_delete(self, exchange: str | None = ..., if_unused: bool = ...): ...
    def exchange_bind(self, destination, source, routing_key: str = ..., arguments: Incomplete | None = ...): ...
    def exchange_unbind(
        self,
        destination: Incomplete | None = ...,
        source: Incomplete | None = ...,
        routing_key: str = ...,
        arguments: Incomplete | None = ...,
    ): ...
    def queue_declare(
        self,
        queue,
        passive: bool = ...,
        durable: bool = ...,
        exclusive: bool = ...,
        auto_delete: bool = ...,
        arguments: Incomplete | None = ...,
    ): ...
    def queue_delete(self, queue, if_unused: bool = ..., if_empty: bool = ...): ...
    def queue_purge(self, queue): ...
    def queue_bind(self, queue, exchange, routing_key: Incomplete | None = ..., arguments: Incomplete | None = ...): ...
    def queue_unbind(
        self, queue, exchange: Incomplete | None = ..., routing_key: Incomplete | None = ..., arguments: Incomplete | None = ...
    ): ...
    def tx_select(self): ...
    def tx_commit(self): ...
    def tx_rollback(self): ...
